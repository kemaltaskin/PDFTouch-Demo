//
//  YLScrollView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLPDFViewController.h"

@class YLPageView;
@class YLTiledView;
@class YLDocument;

/// This is the view that can display one or two PDF pages. It also serves as a container for these
/// page views and can be used to zoom in and out.
@interface YLScrollView : UIScrollView<UIScrollViewDelegate>

/// Page number that is displayed (zero based). This will be the left page in double page mode.
@property (nonatomic, readonly) NSUInteger page;

/// Document mode of the parent YLPDFViewController instance.
@property (nonatomic, assign) YLDocumentMode documentMode;

/// Document lead of the parent YLPDFViewController instance.
@property (nonatomic, assign) YLDocumentLead documentLead;

/// Reference to the first page view.
@property (nonatomic, readonly) YLPageView *leftPageView;

/// Reference to the second page view. This will always be nil in single page mode.
@property (nonatomic, readonly) YLPageView *rightPageView;

/// Reference to the parent YLPDFViewController instance.
@property (nonatomic, assign) YLPDFViewController *pdfViewController;


/** @name Initialization */
/// Initializes a YLScrollView instance and returns it to the caller.
/// @returns An initialized YLScrollView instance.
/// @param frame Frame of this view.
- (id)initWithFrame:(CGRect)frame;

/** @name Display Methods */
/// Use this function to setup this YLScrollView instance.
/// @param document Reference to the document.
/// @param page Page number starting from 0.
- (void)displayDocument:(YLDocument *)document withPage:(NSUInteger)page;

/// Use this function to reset this YLScrollView instance. The internal page views will be removed so that this
/// view can be re-used again.
- (void)invalidate;

/** @name Zoom Methods */
/// Zooms in. The amount of zoom is calculated dynamically when minimum and maximum zoom levels are calculated. The
/// ZOOM_LEVELS value defined in YLGlobal.h determines the amount of zoom levels.
/// @param animated Boolean value that enables/disables animation.
- (void)zoomInAnimated:(BOOL)animated;

/// Zooms out. The amount of zoom is calculated dynamically when minimum and maximum zoom levels are calculated. The
/// ZOOM_LEVELS value defined in YLGlobal.h determines the amount of zoom levels.
/// @param animated Boolean value that enables/disables animation.
- (void)zoomOutAnimated:(BOOL)animated;

/// Restores the zoom value to the default mininum zoom scale.
/// @param animated Boolean value that enables/disables animation.
- (void)resetZoomAnimated:(BOOL)animated;

/** @name Helper Methods */
/// @see See YLPageView for the description of this function.
- (void)updateForSearchResults;

/// @see See YLPageView for the description of this function.
- (void)showAnnotations;

/// @see See YLPageView for the description of this function.
- (void)hideAnnotations;

/// Called by the parent YLPDFViewController to change the frame of this view.
/// @param frame New frame for this view.
- (void)updateContentViewsWithFrame:(CGRect)frame;

@end
