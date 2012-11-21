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

/// This is the view controller that handles searching for text in PDF files. The YLSearchViewController implements the
/// YLSearchDelegate protocol to get updates about the search operation.
@interface YLSearchViewController : UITableViewController<UISearchBarDelegate,UITextFieldDelegate,YLSearchDelegate>

/// The parent controller must set the popover controller that should be used to present the outline view controller.
/// This is only required on the iPad.
@property (nonatomic, assign) UIPopoverController *popoverController;


/// Initializes a YLSearchViewController object and returns it to the caller.
/// @returns An initialized YLSearchViewController instance.
/// @param controller Reference to the parent YLPDFViewController instance.
- (id)initWithPDFController:(YLPDFViewController *)controller;

@end
