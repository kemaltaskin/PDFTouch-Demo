//
//  YLPagesViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/13/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLPDFViewController.h"

@interface YLPagesViewController : UIPageViewController<UIPageViewControllerDelegate,UIPageViewControllerDataSource,UIGestureRecognizerDelegate>

@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, assign) YLDocumentLead documentLead;

- (id)initWithPDFController:(YLPDFViewController *)controller;

- (void)showPage:(NSUInteger)page animated:(BOOL)animated;

@end
