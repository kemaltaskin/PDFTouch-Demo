//
//  YLTiledView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class YLDocument;

@interface YLTiledView : UIView {
    YLDocument *_document;
    NSUInteger _page;
}

- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page;

@end

@interface YLTiledLayer : CATiledLayer
@end
