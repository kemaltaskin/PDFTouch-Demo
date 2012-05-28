//
//  YLAnnotationParser.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/16/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YLAnnotationView.h"

@class YLDocument;
@class YLAnnotation;

@interface YLAnnotationParser : NSObject {
    YLDocument *_document;
}

- (id)initWithDocument:(YLDocument *)document;

- (NSArray *)annotationsForPage:(NSUInteger)page;
- (UIView<YLAnnotationView> *)viewForAnnotation:(YLAnnotation *)annotation frame:(CGRect)frame;


@end
