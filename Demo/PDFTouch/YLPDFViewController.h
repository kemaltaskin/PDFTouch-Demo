//
//  YLPDFViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    YLViewModeDocument = 0,
    YLViewModeThumbnails
} YLViewMode;

typedef enum {
    YLDocumentModeSingle = 0,
    YLDocumentModeDouble
} YLDocumentMode;

typedef enum {
    YLDocumentLeadLeft = 0,
    YLDocumentLeadRight
} YLDocumentLead;

@class YLDocument;
@protocol YLPDFViewControllerDelegate;

@interface YLPDFViewController : UIViewController 

@property (nonatomic, retain) YLDocument *document;
@property (nonatomic, readonly) NSUInteger currentPage;
@property (nonatomic, assign) YLViewMode viewMode;
@property (nonatomic, assign) YLDocumentMode documentMode;
@property (nonatomic, assign) YLDocumentLead documentLead;
@property (nonatomic, assign) BOOL pageCurlEnabled;
@property (nonatomic, assign) NSObject<YLPDFViewControllerDelegate> *delegate;

- (id)initWithDocument:(YLDocument *)document;

- (void)showToolbarsAnimated:(BOOL)animated;
- (void)hideToolbarsAnimated:(BOOL)animated;
- (void)toggleToolbarsAnimated:(BOOL)animated;

- (void)scrollToPage:(NSUInteger)page animated:(BOOL)animated;
- (void)scrollToNextPageAnimated:(BOOL)animated;
- (void)scrollToPreviousPageAnimated:(BOOL)animated;

- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated;

- (void)clearSearchResults;

@end
