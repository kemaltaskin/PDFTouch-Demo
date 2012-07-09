//
//  YLOutlineViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLPDFViewController;

@interface YLOutlineViewController : UITableViewController 

@property (nonatomic, assign) UIPopoverController *popoverController;

- (id)initWithPDFController:(YLPDFViewController *)controller;

@end
