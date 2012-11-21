//
//  YLPagesToolbar.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 4/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLCache.h"

@class YLDocument;
@class YLPDFViewController;
@protocol YLPagesToolbarDelegate;

/// This is the toolbar at the bottom in YLPDFViewController that displays the page thumbnails and also tracks which page number was tapped.
@interface YLPagesToolbar : UIView<YLCacheDelegate> 

/// Delegate that informs which page number was tapped.
@property (nonatomic, assign) NSObject<YLPagesToolbarDelegate> *delegate;

/// Reference to the parent YLPDFViewController.
@property (nonatomic, assign) YLPDFViewController *parentViewController;

/// Returns a reference to the UIToolbar object.
@property (nonatomic, readonly) UIToolbar *toolbar;

/// Initializes a YLPagesToolbar instance and returns it to the caller.
/// @returns An initialized YLPagesToolbar instance.
/// @param frame Frame of the toolbar.
/// @param document Reference to the pdf document.
- (id)initWithFrame:(CGRect)frame document:(YLDocument *)document;

/// This function calculates the number of thumbnails that should be shown and updates the toolbar. The parent
/// YLPDFViewController uses this function to initialize the toolbar and after rotations to update the number
/// of thumbnails shown based on the width of the resized toolbar.
- (void)updateThumbnails;

@end


/// Implement this delegate to get notifications from the pages toolbar about taps on page numbers/thumbnails.
@protocol YLPagesToolbarDelegate<NSObject>
@required
/// Called when the user taps on a page thumbnail.
/// @param toolbar The YLPagesToolbar object informing the delegate.
/// @param page Page number starting from 0.
- (void)pagesToolbar:(YLPagesToolbar *)toolbar tappedOnPage:(NSUInteger)page;
@end
