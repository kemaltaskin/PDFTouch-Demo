//
//  YLPageViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/13/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLPDFViewController;
@class YLPageView;

@interface YLPageViewController : UIViewController

@property (nonatomic, readonly) YLPageView *pageView;
@property (nonatomic, readonly) NSUInteger page;

- (id)initWithPDFController:(YLPDFViewController *)controller page:(NSUInteger)page;

@end
