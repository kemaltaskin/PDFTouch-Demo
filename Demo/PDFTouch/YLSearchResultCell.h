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

@interface YLSearchResultCell : UITableViewCell {
    UILabel *_pageLabel;
    TTTAttributedLabel *_contextLabel;
    
    YLSearchResult *_searchResult;
}

@property (nonatomic, retain) UILabel *pageLabel;
@property (nonatomic, retain) TTTAttributedLabel *contextLabel;
@property (nonatomic, retain) YLSearchResult *searchResult;

@end
