//
//  YLPagesScrollView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/13/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import "YLScrollView.h"

@class YLPagesViewController;
@class YLPDFViewController;

@interface YLPagesScrollView : YLScrollView

@property (nonatomic, readonly) YLPagesViewController *pagesViewController;

- (id)initWithFrame:(CGRect)frame pdfController:(YLPDFViewController *)controller;

- (void)showPage:(NSUInteger)page animated:(BOOL)animated;

@end
