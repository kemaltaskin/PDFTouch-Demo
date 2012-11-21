//
//  YLPageInfo.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/28/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

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

@end
