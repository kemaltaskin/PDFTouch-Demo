//
//  YLCache.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/28/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    YLPDFImageSizeOriginal,             // Original size of the PDF page.
    YLPDFImageSizeThumbnail,            // 200x400
    YLPDFImageSizeSmall                 // 50x100
} YLPDFImageSize;

@class YLDocument;
@class YLOperation;

/// Implement this delegate if you want to get notified about rendered PDF pages.
@protocol YLCacheDelegate <NSObject>
@required
/// Called when YLCache rendered a PDF page into an image.
/// @param document Reference to the document.
/// @param page Page number starting from 0.
/// @param size Size of the rendered image.
/// @param image Rendered image of the PDF page.
- (void)didCacheDocument:(YLDocument *)document page:(NSUInteger)page size:(YLPDFImageSize)size image:(UIImage *)image;
@end


/// YLCache is responsible for all PDF rendering related things. It can render PDF pages into images, load pre-rendered
/// images from disk/memory and save rendered images to memory/disk.
@interface YLCache : NSObject<NSCacheDelegate>

/** @name Initialization */
/// Returns a reference to the singleton YLCache instance.
/// @returns An initialized YLCache instance.
+ (YLCache *)sharedCache;


/** @name Caching Methods */
/// Starts pre-caching the document in the background.
/// @param document Reference to the document.
/// @param page Page number starting from 0. The document will be parsed starting from this page.
/// @param size This defines the type of images that should be created for this document.
- (void)startCachingDocument:(YLDocument *)document startPage:(NSUInteger)page size:(YLPDFImageSize)size;

/// Stops all load/render operations for a specific document.
/// @param document Reference to the document.
- (void)stopCachingDocument:(YLDocument *)document;

/// Cancels a load/render operation.
/// @param operation An instance of YLLoadOperation or YLRenderOperation.
- (void)cancelOperation:(YLOperation *)operation;

/// Use this function to request a pre-rendered image for a specific PDF page.
/// @returns A subclass of YLOperation (YLLoadOperation or YLRenderOperation) or an UIImage instance if the image is available
/// in the cache.
/// @param document Reference to the document.
/// @param page Page number starting from 0.
/// @param size Type of image that should be created for this page.
- (id)cachedImageForDocument:(YLDocument *)document page:(NSUInteger)page size:(YLPDFImageSize)size;


/** @name Delegate Methods */
/// Use this function to register yourself as a delegate.
/// @param delegate Reference to the delegate object.
/// @param delegateQueue The queue on which the delegate should be informed. If you want to get informed on the main thread use
/// dispatch_get_main_queue() here.
- (void)addDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;

/// Use this function to unregister yourself as a delegate.
/// @param delegate Reference to the delegate object.
- (void)removeDelegate:(id)delegate;

/** @name Helper Methods */
/// Use this function to pause rendering/caching operations running in the background. The search operation uses this function
/// to temporarily pause caching while searching for text because it's a CPU-heavy operation.
/// @param caller String value that serves as an identifier. You must use the same identifier when calling resumeCaching!
- (void)pauseCaching:(NSString *)caller;

/// Use this function to resume rendering/caching operations running in the background. Operations will only continue when YLCache
/// is not waiting for other services.
/// @param caller String value that serves as an identifier. Use the same identifier you used when calling pauseCaching!
- (void)resumeCaching:(NSString *)caller;

/// This function will clear the memory cache.
- (void)clearCache;

/// This function will remove the cache on disk for a specific document.
/// @param document Reference to the document.
- (void)clearCacheForDocument:(YLDocument *)document;

@end
