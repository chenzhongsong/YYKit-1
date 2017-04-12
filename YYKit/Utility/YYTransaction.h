//
//  YYTransaction.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/4/18.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//Transaction,n.交易，业务，事务;办理，处理;（一笔）交易，（一项）事务;（学会等的）会议记录，学报
/**
 YYTransaction let you perform a selector once before current runloop sleep.
 */
@interface YYTransaction : NSObject

/**
 Creates and returns a transaction with a specified target and selector.
 
 @param target    A specified target, the target is retained until runloop end.//retained,adj. 保留的 v. 保留；保存（retain的过去式形式）
 @param selector  A selector for target.
 
 @return A new transaction, or nil if an error occurs.
 */
+ (YYTransaction *)transactionWithTarget:(id)target selector:(SEL)selector;

/**
 Commit the trancaction to main runloop.
 
 @discussion It will perform the selector on the target once before main runloop's
 current loop sleep. If the same transaction (same target and same selector) has 
 already commit to runloop in this loop, this method do nothing.
 它将执行选择在目标前一次主runloop的
 电流环睡眠。如果相同的事务（相同的目标和相同的选择器）
 已经提交到runloop在这个循环中，没有这种方法做。
 */
- (void)commit;

@end

NS_ASSUME_NONNULL_END
