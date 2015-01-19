//
//  YLThumbnailCell.h
//
//  Created by Kemal Taskin on 4/7/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import "GMGridViewCell.h"

@class YLDocument;

/// Thumbnail cell used in the grid view to display pdf page thumbnails.
@interface YLThumbnailCell : YLGMGridViewCell

/// A reference to the document.
@property (nonatomic, retain) YLDocument *document;

/// Page number of the thumbnail.
@property (nonatomic, assign) NSUInteger page;

@end
