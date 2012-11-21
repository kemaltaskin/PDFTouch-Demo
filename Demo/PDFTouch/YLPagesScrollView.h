//
//  YLPagesScrollView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/13/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import "YLScrollView.h"

@class YLPagesViewController;
@class YLPDFViewController;

/// Subclass of YLScrollView which is used when page-curl animations are enabled. Unlike YLScrollView there's only one instance
/// of YLPagesScrollView which manages all page views.
@interface YLPagesScrollView : YLScrollView

/// Reference to YLPagesViewController which is a subclass of UIPageViewController.
@property (nonatomic, readonly) YLPagesViewController *pagesViewController;


/** @name Initialization */
/// Initializes a YLPagesScrollView instance and returns it to the caller.
/// @returns An initialized YLPagesScrollView instance.
/// @param frame Frame of this view.
/// @param controller Reference to the parent YLPDFViewController instance.
- (id)initWithFrame:(CGRect)frame pdfController:(YLPDFViewController *)controller;

/** @name Display Methods */
/// Used to navigate to a specific page.
/// @param page Page number starting from 0.
/// @param animated Boolean value that enables/disables animation.
- (void)showPage:(NSUInteger)page animated:(BOOL)animated;

@end
