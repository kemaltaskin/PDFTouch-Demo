//
//  YLScrollView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLPageView;
@class YLTiledView;
@class YLDocument;

@interface YLScrollView : UIScrollView<UIScrollViewDelegate> {
    YLDocument *_document;
    NSUInteger _page;
    
    UIView *_containerView;
    YLPageView *_leftPageView;
    YLPageView *_rightPageView;
}

@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, retain, readonly) YLPageView *leftPageView;
@property (nonatomic, retain, readonly) YLPageView *rightPageView;

- (id)initWithFrame:(CGRect)frame;

- (void)displayDocument:(YLDocument *)document withPage:(NSUInteger)page;

- (void)zoomInAnimated:(BOOL)animated;
- (void)zoomOutAnimated:(BOOL)animated;
- (void)resetZoomAnimated:(BOOL)animated;

- (void)updateContentViewsWithFrame:(CGRect)frame;

@end
