//
//  YLRenderOperation.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 4/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YLOperation.h"

/// This operation will render a PDF page into an image.
@interface YLRenderOperation : YLOperation

/// Set to YES if the rendered image should be cached in memory. Default value is NO.
@property (nonatomic, assign) BOOL shouldCache;
    
@end
