//
//  YLPageView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLCache.h"

@class YLDocument;
@class YLPDFViewController;

/// This is the view that displays the actual PDF page either rendered as an image or rendered
/// real-time by YLTiledView which layer is a CATiledLayer.
@interface YLPageView : UIView<YLCacheDelegate>

/// Reference to the parent YLPDFViewController instance.
@property (nonatomic, assign) YLPDFViewController *pdfViewController;

/** @name Initialization */
/// Initializes a YLPageView object and returns it to the caller.
/// @returns An initialized YLPageView instance.
/// @param document Reference to the document.
/// @param page Page number starting from 0.
- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page;

/** @name Helper Methods */
/// This function checks the document scanner to see if there are any search results on this page
/// that should be highlighted. If so, it enables tiling (rendering done by CATiledLayer) which will
/// highlight text that matches the search term.
- (void)updateForSearchResults;

/// Enables tiling. YLTiledView is initially not created for performance reasons. Instead of rendering
/// the PDF page a pre-rendered image is shown. When the user zooms in (which is detected in the parent YLScrollView)
/// tiling will be enabled.
- (void)enableTiling;

/// Disables tiling which means that the pre-rendered image is shown instead.
- (void)disableTiling;

/// Used to load and show the annotations on this page view.
- (void)showAnnotations;

/// Used to hide the annotations on this page view.
- (void)hideAnnotations;

@end
