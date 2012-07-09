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

@interface YLScrollView : UIScrollView<UIScrollViewDelegate>

@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, assign) YLDocumentMode documentMode;
@property (nonatomic, assign) YLDocumentLead documentLead;
@property (nonatomic, readonly) YLPageView *leftPageView;
@property (nonatomic, readonly) YLPageView *rightPageView;
@property (nonatomic, assign) YLPDFViewController *pdfViewController;

- (id)initWithFrame:(CGRect)frame;

- (void)displayDocument:(YLDocument *)document withPage:(NSUInteger)page;
- (void)invalidate;

- (void)updateForSearchResults;

- (void)showAnnotations;
- (void)hideAnnotations;

- (void)zoomInAnimated:(BOOL)animated;
- (void)zoomOutAnimated:(BOOL)animated;
- (void)resetZoomAnimated:(BOOL)animated;

- (void)updateContentViewsWithFrame:(CGRect)frame;

@end
