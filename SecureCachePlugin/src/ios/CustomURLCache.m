//
//  CustomURLCache.m
//  ebankIT
//
//  Created by Pedro Pereira on 08/07/15.
//  Copyright (c) 2015 ebankIT. All rights reserved.

#import "CustomURLCache.h"
#import "RNDecryptor.h"
#import "RNEncryptor.h"
#import "Configs.h"
#import "FXKeychain.h"

static NSString * const CustomURLCacheExpirationKey = @"CustomURLCacheExpiration";

@implementation CustomURLCache

+ (id)sharedManager {
    static CustomURLCache *_standardURLCache = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        _standardURLCache = [[CustomURLCache alloc]
                             initWithMemoryCapacity:0
                             diskCapacity:0
                             diskPath:nil];
    });
    
    _standardURLCache.encryptKey = [FXKeychain defaultKeychain][@"EBANKITKEY"];
    
    if (_standardURLCache.encryptKey == nil || [_standardURLCache.encryptKey isEqualToString:@""]) {
        [FXKeychain defaultKeychain][@"EBANKITKEY"] = [_standardURLCache generateRandomString:15];
         _standardURLCache.encryptKey = [FXKeychain defaultKeychain][@"EBANKITKEY"];
    }
    
    [NSURLCache setSharedURLCache:_standardURLCache];
    
    return _standardURLCache;
}

#pragma mark - NSURLCache

- (NSCachedURLResponse *)cachedResponseForRequest:(NSURLRequest *)request {
    
    NSCachedURLResponse *cachedResponse = [super cachedResponseForRequest:request];

    if (!cachedResponse) {
        return nil;
    }
    
    if (encryptCache) {
        NSError *error;
        NSData *decryptedData = [RNDecryptor decryptData:cachedResponse.data
                                            withPassword:self.encryptKey
                                                   error:&error];
        
        
        NSMutableDictionary *userInfo = [NSMutableDictionary dictionaryWithDictionary:cachedResponse.userInfo];
        NSCachedURLResponse *modifiedCachedResponse = [[NSCachedURLResponse alloc] initWithResponse:cachedResponse.response data:decryptedData userInfo:userInfo storagePolicy:cachedResponse.storagePolicy];

        return modifiedCachedResponse;
    }else{
        
        return cachedResponse;
    }
}

- (void)storeCachedResponse:(NSCachedURLResponse *)cachedResponse
                 forRequest:(NSURLRequest *)request
{

    NSMutableDictionary *userInfo = [NSMutableDictionary dictionaryWithDictionary:cachedResponse.userInfo];
    
    if (encryptCache) {
        
        NSError *error;
        NSData *encryptedData = [RNEncryptor encryptData:cachedResponse.data
                                            withSettings:kRNCryptorAES256Settings
                                                password:self.encryptKey
                                                   error:&error];
        
        NSCachedURLResponse *modifiedCachedResponse = [[NSCachedURLResponse alloc] initWithResponse:cachedResponse.response data:encryptedData userInfo:userInfo storagePolicy:cachedResponse.storagePolicy];
        
        [super storeCachedResponse:modifiedCachedResponse forRequest:request];
    }
    else{
        
        NSCachedURLResponse *modifiedCachedResponse = [[NSCachedURLResponse alloc] initWithResponse:cachedResponse.response data:cachedResponse.data userInfo:userInfo storagePolicy:cachedResponse.storagePolicy];

        [super storeCachedResponse:modifiedCachedResponse forRequest:request];
    }
}

- (NSString *)generateRandomString:(NSInteger)len
{
    NSString *letters = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXZY0123456789,./;'[]{}!@#$%^&*()_+";
    NSMutableString *randomString = [NSMutableString stringWithCapacity:len];
    
    for (int i=0; i<len; i++)
        [randomString appendFormat: @"%C", [letters characterAtIndex: arc4random() % [letters length]]];
    
    return randomString;
}

@end