/********* SecureCache.m Cordova Plugin Implementation *******/

#import <Cordova/CDV.h>
#import "CustomURLCache.h"

@interface SecureCache : CDVPlugin {
    // Member variables go here.
}

//secure cache methods
- (void)initSecureCache:(CDVInvokedUrlCommand*)command;

@end

@implementation SecureCache

- (void)initSecureCache:(CDVInvokedUrlCommand*)command {
    CDVPluginResult* pluginResult = nil;
    
    [CustomURLCache sharedManager];
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"SecureCache Initialized!"];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    
}

@end
