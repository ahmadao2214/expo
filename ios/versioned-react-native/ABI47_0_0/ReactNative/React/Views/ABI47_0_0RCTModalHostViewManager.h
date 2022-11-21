/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI47_0_0React/ABI47_0_0RCTConvert.h>
#import <ABI47_0_0React/ABI47_0_0RCTInvalidating.h>
#import <ABI47_0_0React/ABI47_0_0RCTViewManager.h>

@interface ABI47_0_0RCTConvert (ABI47_0_0RCTModalHostView)

+ (UIModalPresentationStyle)UIModalPresentationStyle:(id)json;

@end

typedef void (^ABI47_0_0RCTModalViewInteractionBlock)(
    UIViewController *ABI47_0_0ReactViewController,
    UIViewController *viewController,
    BOOL animated,
    dispatch_block_t completionBlock);

@interface ABI47_0_0RCTModalHostViewManager : ABI47_0_0RCTViewManager <ABI47_0_0RCTInvalidating>

/**
 * `presentationBlock` and `dismissalBlock` allow you to control how a Modal interacts with your case,
 * e.g. in case you have a native navigator that has its own way to display a modal.
 * If these are not specified, it falls back to the UIViewController standard way of presenting.
 */
@property (nonatomic, strong) ABI47_0_0RCTModalViewInteractionBlock presentationBlock;
@property (nonatomic, strong) ABI47_0_0RCTModalViewInteractionBlock dismissalBlock;

@end
