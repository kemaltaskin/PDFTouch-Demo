//
//  YLExtractTextOperation.h
//
//  Created by Kemal Taskin on 3/8/13.
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YLOperation.h"

@class YLDocument;

@interface YLExtractTextOperation : YLOperation

- (id)initWithDocument:(YLDocument *)document;

@end
