//
//  YLPDFViewControllerDelegate.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/21/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLPDFViewController, YLDocument, YLAnnotation;

@protocol YLPDFViewControllerDelegate <NSObject>
@optional
- (void)pdfViewController:(YLPDFViewController *)controller didDisplayDocument:(YLDocument *)document;
// return YES if you want to handle the target of the annotation
- (BOOL)pdfViewController:(YLPDFViewController *)controller tappedOnAnnotation:(YLAnnotation *)annotation;
@end
