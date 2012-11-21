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

/// This is the view that hosts the real-time rendered PDF page. The layer of this view is a CATiledLayer.
@interface YLTiledView : UIView 

/** @name Initialization */
/// Initializes a YLTiledView instance and returns it to the caller.
/// @returns An initialized YLTiledView instance.
/// @param document Reference to the document.
/// @param page Page number starting from 0.
- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page;

@end

/// Custom CATiledLayer which calculates tile sizes and configures the number of zoom levels.
@interface YLTiledLayer : CATiledLayer
@end
