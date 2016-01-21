//
//  RealReachability.h
//  Version 1.0.0
//
//  Created by Dustturtle on 16/1/9.
//  Copyright (c) 2016 Dustturtle. All rights reserved.
//
// This code is distributed under the terms and conditions of the MIT license.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

#define GLobalRealReachability [RealReachability sharedInstance]

//This notification was called only when reachability really changed;
//We use FSM to promise this for you;
//We post self to this notification, then you can invoke currentReachabilityStatus method to fetch current status.
extern NSString *const kRealReachabilityChangedNotification;

typedef NS_ENUM(NSInteger, ReachabilityStatus) {
    // Apple NetworkStatus Compatible Names.
    NotReachable = 0,
    ReachableViaWWAN = 1,
    ReachableViaWiFi = 2
};

@interface RealReachability : NSObject

// Please make sure this host is available for pinging!
@property (nonatomic, copy) NSString *hostForPing;

+ (instancetype)sharedInstance;

- (void)startNotifier;

- (void)stopNotifier;

/**
 *  To get real reachability we need to do async request,
 *  then we use the block blow for invoker to handle business request(need real reachability).
 *
 *  @param asyncHandler async request handler, return in 2 seconds(max limit).
 */
- (void)reachabilityWithBlock:(void (^)(ReachabilityStatus))asyncHandler;

/**
 *  Return current reachability immediately.
 *
 *  @return see enum LocalConnectionStatus
 */
- (ReachabilityStatus)currentReachabilityStatus;


@end
