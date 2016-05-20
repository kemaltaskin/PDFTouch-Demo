//
//  YLSearchStatusCell.h
//
//  Created by Kemal Taskin on 5/3/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

/** Search status */
typedef NS_ENUM(NSInteger, YLSearchStatus) {
    /** Searching state */
    kSearchStatusSearching,
    /** Stopped state */
    kSearchStatusStopped
};

/// Custom table view cell that shows progress information about the search operation.
@interface YLSearchStatusCell : UITableViewCell

/// Current status of the search operation.
@property (nonatomic, assign) YLSearchStatus searchStatus;

/// Returns the primary label used to display the status.
@property (nonatomic, readonly) UILabel *statusLabel;

/// Returns the secondary label used to display additional information.
@property (nonatomic, readonly) UILabel *detailLabel;

/// Returns the activity indicator that spins while search continues.
@property (nonatomic, readonly) UIActivityIndicatorView *spinner;

@end
