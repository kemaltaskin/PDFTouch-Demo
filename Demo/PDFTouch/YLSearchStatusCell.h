//
//  YLSearchStatusCell.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/3/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    kSearchStatusSearching,
    kSearchStatusStopped
} SearchStatus;

/// Custom table view cell that shows progress information about the search operation.
@interface YLSearchStatusCell : UITableViewCell

/// Current status of the search operation.
@property (nonatomic, assign) SearchStatus searchStatus;

/// Returns the primary label used to display the status.
@property (nonatomic, readonly) UILabel *statusLabel;

/// Returns the secondary label used to display additional information.
@property (nonatomic, readonly) UILabel *detailLabel;

/// Returns the activity indicator that spins while search continues.
@property (nonatomic, readonly) UIActivityIndicatorView *spinner;

@end
