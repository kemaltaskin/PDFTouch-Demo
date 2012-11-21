//
//  YLPagesViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/13/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLPDFViewController.h"

/// This is the view controller that manages page swipes and also supplies the view controllers requested
/// by the UIPageViewControllerDataSource protocol.
@interface YLPagesViewController : UIPageViewController<UIPageViewControllerDelegate,UIPageViewControllerDataSource,UIGestureRecognizerDelegate>

/// Current page number (zero based).
@property (nonatomic, readonly) NSUInteger page;

/// Document lead of the parent YLPDFViewController instance.
@property (nonatomic, assign) YLDocumentLead documentLead;

/** @name Initialization */
/// Initializes a YLPagesViewController instance and returns it to the caller.
/// @returns An initialized YLPagesViewController instance.
/// @param controller Reference to the parent YLPDFViewController instance.
- (id)initWithPDFController:(YLPDFViewController *)controller;

/** Display Methods */
/// Used to navigate to a specific page.
/// @param page Page number starting from 0.
/// @param animated Boolean value that enables/disables animation.
- (void)showPage:(NSUInteger)page animated:(BOOL)animated;

@end
