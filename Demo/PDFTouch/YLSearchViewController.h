//
//  YLSearchViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLSearchOperation.h"

@class YLPDFViewController;

@interface YLSearchViewController : UITableViewController<UISearchBarDelegate,UITextFieldDelegate,YLSearchDelegate> {
    YLPDFViewController *_pdfViewController;
    UIPopoverController *_poController;
}

@property (nonatomic, assign) UIPopoverController *popoverController;

- (id)initWithPDFController:(YLPDFViewController *)controller;

@end
