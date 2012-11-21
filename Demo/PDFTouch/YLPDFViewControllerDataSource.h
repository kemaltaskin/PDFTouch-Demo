//
//  YLPDFViewControllerDataSource.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 11/12/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YLAnnotationView.h"

/// Implement this protocol in your UIViewController to provide additional data that should be displayed on pdf pages.
@protocol YLPDFViewControllerDataSource <NSObject>
@optional

///Use this function to return an array of UIViews that conform to the YLAnnotationView protocol!
///@param controller The YLPDFViewController object requesting this information.
///@param page page number starting from 0.
///@param viewRect CGRect of pdf page in view coordinates.
- (NSArray *)pdfViewController:(YLPDFViewController *)controller annotationViewsForPage:(NSUInteger)page viewRect:(CGRect)viewRect;

@end
