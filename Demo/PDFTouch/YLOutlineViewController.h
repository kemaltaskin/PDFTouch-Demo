//
//  YLOutlineViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLPDFViewController;

/// This view controller is used to display the outline a PDF file.
@interface YLOutlineViewController : UITableViewController 

/// The parent controller must set the popover controller that should be used to present the outline view controller.
/// This is only required on the iPad.
@property (nonatomic, assign) UIPopoverController *popoverController;

/// Initializes a YLOutlineViewController object and returns it to the caller.
/// @returns An initialized YLOutlineViewController instance.
/// @param controller Reference to the parent YLPDFViewController instance.
- (id)initWithPDFController:(YLPDFViewController *)controller;

@end
