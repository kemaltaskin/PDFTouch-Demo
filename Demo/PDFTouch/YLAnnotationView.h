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

/// All annotation views should implement this protocol to display YLAnnotation objecs and react to page hide/show events.
@protocol YLAnnotationView <NSObject>

/// Weak reference to parent YLPDFViewController.
@property (nonatomic, assign) YLPDFViewController *pdfViewController;

/// The annotation object represented by this view.
@property (nonatomic, retain) YLAnnotation *annotation;

/// Called when page is shown.
/// @param page Page number starting from 0.
- (void)didShowPage:(NSUInteger)page;

/// Called when page is hidden.
/// @param page Page number starting from 0.
- (void)willHidePage:(NSUInteger)page;

@end
