/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "ABI47_0_0RCTViewUtils.h"

#import "ABI47_0_0UIView+React.h"

UIEdgeInsets ABI47_0_0RCTContentInsets(UIView *view)
{
  while (view) {
    UIViewController *controller = view.ABI47_0_0ReactViewController;
    if (controller) {
      return controller.view.safeAreaInsets;
    }
    view = view.superview;
  }
  return UIEdgeInsetsZero;
}
