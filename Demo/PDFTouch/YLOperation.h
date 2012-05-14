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

@interface YLOperation : NSOperation {
    YLDocument *_document;
    NSUInteger _page;
    YLPDFImageSize _size;
    NSString *_path;
    
    UIImage *_image;
}

@property (nonatomic, readonly) YLDocument *document;
@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, readonly) YLPDFImageSize size;
@property (nonatomic, readonly) NSString *path;
@property (nonatomic, retain) UIImage *image;

- (id)initWithDocument:(YLDocument *)document page:(NSUInteger)page size:(YLPDFImageSize)size path:(NSString *)path;

@end
