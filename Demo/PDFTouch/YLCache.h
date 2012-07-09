//
//  YLCache.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/28/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    YLPDFImageSizeOriginal,
    YLPDFImageSizeThumbnail,
    YLPDFImageSizeSmall
} YLPDFImageSize;

@class YLDocument;

@protocol YLCacheDelegate <NSObject>
- (void)didCacheDocument:(YLDocument *)document page:(NSUInteger)page size:(YLPDFImageSize)size image:(UIImage *)image;
@end

@interface YLCache : NSObject<NSCacheDelegate>

+ (YLCache *)sharedCache;

- (void)startCachingDocument:(YLDocument *)document startPage:(NSUInteger)page size:(YLPDFImageSize)size;
- (void)stopCachingDocument:(YLDocument *)document;

- (id)cachedImageForDocument:(YLDocument *)document page:(NSUInteger)page size:(YLPDFImageSize)size;

- (void)addDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate;

- (void)pauseCaching:(NSString *)caller;
- (void)resumeCaching:(NSString *)caller;

- (void)clearCache;
- (void)clearCacheForDocument:(YLDocument *)document;

@end
