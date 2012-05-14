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

@interface YLSearchStatusCell : UITableViewCell {
    SearchStatus _searchStatus;
    
    UILabel *_statusLabel;
    UILabel *_detailLabel;
    UIActivityIndicatorView *_spinner;
}

@property (nonatomic, assign) SearchStatus searchStatus;
@property (nonatomic, retain) UILabel *statusLabel;
@property (nonatomic, retain) UILabel *detailLabel;
@property (nonatomic, retain) UIActivityIndicatorView *spinner;

@end
