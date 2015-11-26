//
//  YLSearchViewController.h
//
//  Created by Kemal Taskin on 5/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLSearchOperation.h"

@class YLPDFViewController;

/// This is the view controller that handles searching for text in PDF files. The YLSearchViewController implements the
/// YLSearchDelegate protocol to get updates about the search operation.
@interface YLSearchViewController : UITableViewController<UISearchBarDelegate,YLSearchDelegate,UIPopoverPresentationControllerDelegate>

/// Initializes a YLSearchViewController object and returns it to the caller.
/// @returns An initialized YLSearchViewController instance.
/// @param controller Reference to the parent YLPDFViewController instance.
- (id)initWithPDFController:(YLPDFViewController *)controller;

@end
