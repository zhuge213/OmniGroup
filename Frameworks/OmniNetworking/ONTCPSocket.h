// Copyright 1997-2005 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import "ONInternetSocket.h"

@interface ONTCPSocket : ONInternetSocket
{
    struct {
        unsigned int useNagle: 2;
        unsigned int pushWrites: 2;
    } tcpFlags;
}

+ (Class)defaultTCPSocketClass;
+ (void)setDefaultTCPSocketClass:(Class)aClass;

+ (ONTCPSocket *)tcpSocket;
    // This creates a socket of the defaultTCPSocketClass

- (void)startListeningOnAnyLocalPort;
- (void)startListeningOnLocalPort:(unsigned short int)port;
- (void)startListeningOnLocalPort:(unsigned short int)port allowingAddressReuse:(BOOL)reuse;
- (void)startListeningOnLocalService:(ONServiceEntry *)service;

- (void)acceptConnection;
- (ONTCPSocket *)acceptConnectionOnNewSocket;

- (void)setUsesNagleDelay:(BOOL)nagle;
// - (BOOL)usesNagleDelay;

- (void)setPushesWrites:(BOOL)push;
// - (BOOL)pushesWrites;

@end

#import "FrameworkDefines.h"

// Exceptions which may be raised by this class
OmniNetworking_EXTERN NSString *ONTCPSocketListenFailedExceptionName;
OmniNetworking_EXTERN NSString *ONTCPSocketAcceptFailedExceptionName;
OmniNetworking_EXTERN NSString *ONTCPSocketWouldBlockExceptionName;
