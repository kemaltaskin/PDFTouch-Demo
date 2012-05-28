//
//  YLAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/16/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLAnnotation;
@class YLPDFViewController;

@protocol YLAnnotationView <NSObject>

@property (nonatomic, assign) YLPDFViewController *pdfViewController;
@property (nonatomic, retain) YLAnnotation *annotation;

- (void)didShowPage:(NSUInteger)page;
- (void)willHidePage:(NSUInteger)page;

@end
