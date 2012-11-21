//
//  YLPDFViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    YLViewModeDocument = 0,         // View mode that displays the PDF document.
    YLViewModeThumbnails,           // View mode that displays page thumbnails.
    YLViewModeBookmarks             // View mode that displays thumbnails for bookmarked pages.
} YLViewMode;

typedef enum {
    YLDocumentModeSingle = 0,       // Show single page per view. (Default)
    YLDocumentModeDouble            // Show two pages per view.
} YLDocumentMode;

typedef enum {
    YLDocumentLeadLeft = 0,         // First page starts left in double page mode. (Default)
    YLDocumentLeadRight             // First page starts right in double page mode.
} YLDocumentLead;

@class YLDocument;
@protocol YLPDFViewControllerDelegate;
@protocol YLPDFViewControllerDataSource;

/// This is the main view controller you should use to display PDF documents.
@interface YLPDFViewController : UIViewController 

/// Document that should be displayed.
@property (nonatomic, retain) YLDocument *document;

/// Current page number (zero based). This value will always the left page number when in double page mode.
@property (nonatomic, readonly) NSUInteger currentPage;

/// Current view mode.
@property (nonatomic, assign) YLViewMode viewMode;

/// Current document mode.
@property (nonatomic, assign) YLDocumentMode documentMode;

/// Current document lead.
@property (nonatomic, assign) YLDocumentLead documentLead;

/// Default value is NO. Use this property to enable page-curl animations.
@property (nonatomic, assign) BOOL pageCurlEnabled;

/// Default value is NO. Use this property to enable auto-layout. Auto-layout will show single pages in portrait mode and double pages in
/// landscape mode. Note: auto-layout only works in YLDocumentModeDouble mode. Be sure that the document mode is set to double pages before
/// enabling auto-layout.
@property (nonatomic, assign) BOOL autoLayoutEnabled;

/// Reference to the delegate that should be informed.
@property (nonatomic, assign) IBOutlet NSObject<YLPDFViewControllerDelegate> *delegate;

/// Reference to the datasource that should be used to request additional information.
@property (nonatomic, assign) IBOutlet NSObject<YLPDFViewControllerDataSource> *datasource;

/** @name Initialization */
/// Initializes a YLPDFViewController object and returns it to the caller.
/// @returns An initialized YLPDFViewController instance.
/// @param document Model object of the PDF document.
- (id)initWithDocument:(YLDocument *)document;

/** @name Toolbar Handling */
/// Shows the top and bottom toolbars.
/// @param animated Boolean value that enables/disables animation.
- (void)showToolbarsAnimated:(BOOL)animated;

/// Hides the top and bottom toolbars.
/// @param animated Boolean value that enables/disables animation.
- (void)hideToolbarsAnimated:(BOOL)animated;

/// Toggles the visibility of the top and bottom toolbars.
/// @param animated Boolean value that enables/disables animation.
- (void)toggleToolbarsAnimated:(BOOL)animated;

/** @name Page Scrolling */
/// Scrolls to the specified page.
/// @param page Page number starting from 0.
/// @param animated Boolean value that enables/disables animation.
- (void)scrollToPage:(NSUInteger)page animated:(BOOL)animated;

/// Scrolls to the next page if there is one.
/// @param animated Boolean value that enables/disables animation.
- (void)scrollToNextPageAnimated:(BOOL)animated;

/// Scrolls to the previous page if there is one.
/// @param animated Boolean value that enables/disables animation.
- (void)scrollToPreviousPageAnimated:(BOOL)animated;

/** @name Helper Methods */
/// This function is used by the annotation views to present a modal view controller.
/// @param modalViewController The view controller that should be presented.
/// @param animated Boolean value that enables/disables animation.
- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated;

/// This function is used by the search view controller to clear previous text-highlights on pdf pages.
- (void)clearSearchResults;

@end
