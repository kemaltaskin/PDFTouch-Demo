//
//  YLThumbnailCell.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 4/7/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import "GMGridViewCell.h"
#import "YLCache.h"

@class YLDocument;

@interface YLThumbnailCell : GMGridViewCell<YLCacheDelegate>

@property (nonatomic, retain) YLDocument *document;
@property (nonatomic, assign) NSUInteger page;

@end
