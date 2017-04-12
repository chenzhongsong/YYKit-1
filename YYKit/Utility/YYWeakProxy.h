//
//  YYWeakProxy.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 14/10/18.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//Proxy,n. 代表权;代理权(尤指投票);代理人,代表.
//代理服务器，即Proxy服务器，在互联网上的完成跑腿服务。当你在浏览器中设置了某个Proxy服务器之后，由你的浏览器所发出的任何要求，都会被送到Proxy服务器上去，由这台Proxy服务器代为处理。
/**
 A proxy used to hold a weak object.
 It can be used to avoid retain cycles, such as the target in NSTimer or CADisplayLink.
 用于保持弱对象的代理。
 它可以用来避免保留周期(循环引用)，如cadisplaylink NSTimer或目标。
 sample code:
 
     @implementation MyView {
        NSTimer *_timer;
     }
     
     - (void)initTimer {
        YYWeakProxy *proxy = [YYWeakProxy proxyWithTarget:self];
        _timer = [NSTimer timerWithTimeInterval:0.1 target:proxy selector:@selector(tick:) userInfo:nil repeats:YES];
     }
     
     - (void)tick:(NSTimer *)timer {...}
     @end
 */
@interface YYWeakProxy : NSProxy

/**
 The proxy target.//代理目标
 */
@property (nullable, nonatomic, weak, readonly) id target;

/**
 Creates a new weak proxy for target.
 
 @param target Target object.
 
 @return A new proxy object.
 */
- (instancetype)initWithTarget:(id)target;

/**
 Creates a new weak proxy for target.
 
 @param target Target object.
 
 @return A new proxy object.
 */
+ (instancetype)proxyWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_END
