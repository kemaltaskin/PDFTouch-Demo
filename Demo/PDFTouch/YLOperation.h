//
//  YLOperation.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 4/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YLCache.h"

@class YLDocument;

/// This is the base class for all operations used by YLCache to load/render/write pre-rendered images.
@interface YLOperation : NSOperation {
    YLDocument *_document;
    NSUInteger _page;
    YLPDFImageSize _size;
    NSString *_path;
    
    UIImage *_image;
}

/// Reference to the document.
@property (nonatomic, readonly) YLDocument *document;

/// Page number starting from 0.
@property (nonatomic, readonly) NSUInteger page;

/// Type of the image.
@property (nonatomic, readonly) YLPDFImageSize size;

/// Reference to the path of the image.
@property (nonatomic, readonly) NSString *path;

/// Reference to the image.
@property (nonatomic, retain) UIImage *image;


/** @name Initialization */
/// Initializes a YLOperation instance and returns it to the caller.
/// @returns An initialized YLOperation instance.
/// @param document Reference to the document.
/// @param page Page number starting from 0.
/// @param size Type of image.
/// @param path Filesystem path that should be used to load/write an image from/to.
- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page size:(YLPDFImageSize)size path:(NSString *)path;

@end
