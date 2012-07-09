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

@interface YLPagesToolbar : UIView<YLCacheDelegate> 

@property (nonatomic, assign) NSObject<YLPagesToolbarDelegate> *delegate;
@property (nonatomic, assign) YLPDFViewController *parentViewController;
@property (nonatomic, readonly) UIToolbar *toolbar;

- (id)initWithFrame:(CGRect)frame document:(YLDocument *)document;

- (void)updateThumbnails;

@end


@protocol YLPagesToolbarDelegate<NSObject>
@required
- (void)pagesToolbar:(YLPagesToolbar *)toolbar tappedOnPage:(NSUInteger)page;
@end
