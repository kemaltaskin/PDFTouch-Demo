//
//  YLPageViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/13/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLPDFViewController;
@class YLPageView;

/// This is the container view controller that holds one instance of YLPageView and is used in YLPagesViewController
/// to represent a single page view.
@interface YLPageViewController : UIViewController

/// Reference to the page view.
@property (nonatomic, readonly) YLPageView *pageView;

/// Page number (zero based).
@property (nonatomic, readonly) NSUInteger page;


/** Initialization */
/// Initializes a YLPageViewController instance and returns it to the caller.
/// @returns An initialized YLPageViewController instance.
/// @param controller Reference to the parent YLPDFViewController instance.
/// @param page Page number starting from 0.
- (id)initWithPDFController:(YLPDFViewController *)controller page:(NSUInteger)page;

@end
