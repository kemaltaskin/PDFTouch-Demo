//
//  YLAnnotation.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/16/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLDocument;
@class YLPageInfo;

typedef enum {
    kAnnotationTypeInvalid = 0,
    kAnnotationTypePage,
    kAnnotationTypeLink,
    kAnnotationTypeVideo,
    kAnnotationTypeAudio,
    kAnnotationTypeWeb,
    kAnnotationTypeMap,
    kAnnotationTypeCustom
} AnnotationType;

/// Model object that holds information about an annotation.
@interface YLAnnotation : NSObject 

/// Rectangle of the annotation in pdf coordinates.
@property (nonatomic, readonly) CGRect rect;

/// Page number of the annotation.
@property (nonatomic, readonly) NSUInteger page;

/// This holds the target page number if the annotation is of type kAnnotationTypePage.
@property (nonatomic, readonly) NSNumber *targetPage;

/// The complete original url as it appears in the annotation.
@property (nonatomic, readonly) NSString *uri;

/// This is the parsed url that will point to web pages or remote audio/video.
@property (nonatomic, readonly) NSURL *url;

/// Dictionary holding the parameters that were passed in the annotation url.
@property (nonatomic, readonly) NSDictionary *params;

/// Boolean value that specifies wether the audio/video annotation's content is local or remote.
@property (nonatomic, readonly) BOOL local;

/// Reference to the YLDocument object.
@property (nonatomic, assign) YLDocument *document;

/// Type of the annotation.
@property (nonatomic, readonly) AnnotationType type;

/// Converts a point from PDF coordinates to view coordinates.
/// @returns Point that is converted to view coordinates.
/// @param pdfPoint Point in PDF coordinates.
/// @param renderRect Target rectangle that will hold the point.
/// @param pageInfo YLPageInfo object of the page that contains the point.
+ (CGPoint)convertPDFPointToViewPoint:(CGPoint)pdfPoint renderRect:(CGRect)renderRect pageInfo:(YLPageInfo *)pageInfo;

/// Converts a point from view coordinates to PDF coordinates.
/// @returns Point that is converted to PDF coordinates.
/// @param viewPoint Point in view coordinates.
/// @param renderRect Target rectangle that will hold the point.
/// @param pageInfo YLPageInfo object of the page that contains the point.
+ (CGPoint)convertViewPointToPDFPoint:(CGPoint)viewPoint renderRect:(CGRect)renderRect pageInfo:(YLPageInfo *)pageInfo;

/// Converts a rectangle from PDF coordinates to view coordinates.
/// @returns Rectangle that is converted to view coordinates.
/// @param pdfRect Rectangle in PDF coordinates.
/// @param renderRect Target view rectangle.
/// @param pageInfo YLPageInfo object of the page that contains the rectangle.
+ (CGRect)convertPDFRect:(CGRect)pdfRect forRect:(CGRect)renderRect pageInfo:(YLPageInfo *)pageInfo;

/// Initializes a YLAnnotation object and returns it to the caller.
/// @returns An initialized YLAnnotation object.
/// @param document Reference to the CGPDF document object.
/// @param dictionary Dictionary that holds all the information about the annotation.
/// @param page Page number of the annotation.
- (id)initWithDocument:(CGPDFDocumentRef)document dictionary:(CGPDFDictionaryRef)dictionary page:(NSUInteger)page;

/// Converts the rectangle of the annotation to view coordinates using the passed rect parameter as the target container rectangle.
/// @returns Rectangle converted to view coordinates.
/// @param rect The target container rectangle. This could be the bounds rectangle of the UIView where the PDF page is rendered in for example.
- (CGRect)viewRectForRect:(CGRect)rect;

@end
