//
//  YLPageView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLCache.h"

@class YLTiledView;
@class YLDocument;

@interface YLPageView : UIView<YLCacheDelegate> {
    YLDocument *_document;
    NSUInteger _page;
    
    UIImageView *_imageView;
    YLTiledView *_tiledView;
}

- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page;

- (void)updateForSearchResults;

- (void)enableTiling;
- (void)disableTiling;

@end
