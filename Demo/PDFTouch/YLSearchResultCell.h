//
//  YLSearchResultCell.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/3/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TTTAttributedLabel;
@class YLSearchResult;

/// Table cell used to display search results in the table view.
@interface YLSearchResultCell : UITableViewCell 

/// Returns the label used to display the page number.
@property (nonatomic, readonly) UILabel *pageLabel;

/// Returns the label used to display a short overview where the result appears in. The search term will be displayed bold.
@property (nonatomic, readonly) TTTAttributedLabel *contextLabel;

/// The model object that holds information about the search result.
@property (nonatomic, retain) YLSearchResult *searchResult;

@end
