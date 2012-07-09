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

@interface YLPageView : UIView<YLCacheDelegate>

@property (nonatomic, assign) YLPDFViewController *pdfViewController;

- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page;

- (void)updateForSearchResults;

- (void)enableTiling;
- (void)disableTiling;

- (void)showAnnotations;
- (void)hideAnnotations;

@end
