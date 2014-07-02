//
//  YLPDFViewControllerDelegate.h
//
//  Created by Kemal Taskin on 5/21/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLPDFViewController, YLDocument, YLAnnotation, YLPageView;
@protocol YLAnnotationView;

/// Implement this delegate in your UIViewController to get notified about YLPDFViewController and change
/// its behaviour.
@protocol YLPDFViewControllerDelegate <NSObject>
@optional

/// Called when YLPDFViewController finished loading document.
///@param controller The YLPDFViewController object informing the delegate.
///@param document The YLDocument object displayed by the controller.
- (void)pdfViewController:(YLPDFViewController *)controller didDisplayDocument:(YLDocument *)document;

/// Called when YLPDFViewController will be dismissed (when the done button is tapped).
///@param controller The YLPDFViewController object informing the delegate.
///@param document The YLDocument object displayed by the controller.
- (void)pdfViewController:(YLPDFViewController *)controller willDismissDocument:(YLDocument *)document;

/// Called when a page view is shown.
///@param controller The YLPDFViewController object informing the delegate.
///@param page The page number that's currently shown.
- (void)pdfViewController:(YLPDFViewController *)controller didShowPage:(NSUInteger)page;

/// Return YES if you want to override the default action for this annotation. The default value is NO.
///@param controller The YLPDFViewController object requesting this information.
///@param annotation The YLAnnotation object that was tapped on.
- (BOOL)pdfViewController:(YLPDFViewController *)controller tappedOnAnnotation:(YLAnnotation *)annotation;

/// Called before an annotation view is added to a page. You can use this function to configure the appearance
/// of annotation views.
///@param controller The YLPDFViewController object informing the delegate.
///@param annotationView The annotation view conforming to the YLAnnotationView protocol.
///@param pageView The view object which represents the page.
- (void)pdfViewController:(YLPDFViewController *)controller willDisplayAnnotationView:(UIView<YLAnnotationView> *)annotationView onPageView:(YLPageView *)pageView;

@end
