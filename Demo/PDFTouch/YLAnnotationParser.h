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

/// YLAnnotationParser is responsible for parsing the annotations in a PDF file.
@interface YLAnnotationParser : NSObject

/** @name Initialization */
/// Initializes a YLAnnotationParser instance and returns it to the caller.
/// @returns An initialized YLAnnotationParser instance.
/// @param document Reference to the document.
- (id)initWithDocument:(YLDocument *)document;

/** @name Annotation Methods */
/// Returns the annotations for a specific page.
/// @returns An array with YLAnnotation objects.
/// @param page Page number starting from 0.
- (NSArray *)annotationsForPage:(NSUInteger)page;

/// Returns a view for a given annotation that conforms to the YLAnnotationView protocol.
/// @returns A view that conforms to the YLAnnotationView protocol.
/// @param annotation Annotation object.
/// @param frame Frame of the annotation in view coordinates. Use the viewRectForRect method in YLAnnotation to
/// convert the annotation's frame from PDF coordinates to view coordinates.
- (UIView<YLAnnotationView> *)viewForAnnotation:(YLAnnotation *)annotation frame:(CGRect)frame;


@end
