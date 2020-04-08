//
//  CustomURLCache.h
//  ebankIT
//
//  Created by Pedro Pereira on 08/07/15.
//  Copyright (c) 2015 ebankIT. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CustomURLCache : NSURLCache

@property (strong, nonatomic) NSString* encryptKey;
+ (id)sharedManager;

@end
