//
//  YLPageInfo.h
//
//  Created by Kemal Taskin on 3/28/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

typedef enum {
    YLPDFImageSizeOriginal,             // Original size of the PDF page.
    YLPDFImageSizeThumbnail,            // 200x400
    YLPDFImageSizeSmall                 // 50x100
} YLPDFImageSize;

/// Model object that holds various information about a PDF page like rectangle, rotation and page number.
@interface YLPageInfo : NSObject

/// CGRect value holding the original rectangle value as specified in the PDF file. This value is obtained using the kCGPDFCropBox type.
@property (nonatomic, readonly) CGRect origRect;

/// CGRect value holding the rotated original rectangle.
@property (nonatomic, readonly) CGRect rotatedRect;

/// Rotation angle of the page.
@property (nonatomic, readonly) int rotation;

/// Page number.
@property (nonatomic, readonly) NSUInteger page;

/// Initializes a YLPageInfo object and returns it to the caller.
/// @returns An initialized YLPageInfo object.
/// @param page The page number (starting from 0).
/// @param rect The original rectangle.
/// @param rotation The rotation angle.
+ (YLPageInfo *)YLPageInfoWithPage:(NSUInteger)page rect:(CGRect)rect rotation:(int)rotation;

/// Initializes a YLPageInfo object and returns it to the caller.
/// @returns An initialized YLPageInfo object.
/// @param page The page number (starting from 0).
/// @param rect The original rectangle.
/// @param rotation The rotation angle.
- (id)initWithPage:(NSUInteger)page rect:(CGRect)rect rotation:(int)rotation;

/// Calculates the target page rectangle for a specific size and caches the result for future usage.
/// @returns A CGRect value with the correct aspect ratio and offset for the specified size.
/// @param size Size of the target rectangle.
- (CGRect)targetRectForSize:(YLPDFImageSize)size;

@end
