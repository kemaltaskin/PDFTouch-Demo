//
//  YLAnnotation.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/16/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLDocument;

typedef enum {
    kAnnotationTypeInvalid = 0,
    kAnnotationTypePage,
    kAnnotationTypeLink,
    kAnnotationTypeVideo,
    kAnnotationTypeWeb,
    kAnnotationTypeOther
} AnnotationType;

@interface YLAnnotation : NSObject 

@property (nonatomic, readonly) CGRect rect;
@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, readonly) NSNumber *targetPage;
@property (nonatomic, readonly) NSString *uri;
@property (nonatomic, readonly) NSURL *url;
@property (nonatomic, readonly) NSDictionary *params;
@property (nonatomic, assign) YLDocument *document;
@property (nonatomic, readonly) AnnotationType type;

- (id)initWithDocument:(CGPDFDocumentRef)document dictionary:(CGPDFDictionaryRef)dictionary page:(NSUInteger)page;

- (CGRect)viewRectForRect:(CGRect)rect;

@end
