//
//  YLPDFViewControllerDelegate.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/21/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLPDFViewController, YLDocument, YLAnnotation;

/// Implement this delegate in your UIViewController to get notified about YLPDFViewController and change
/// its behaviour.
@protocol YLPDFViewControllerDelegate <NSObject>
@optional

/// Called when YLPDFViewController finished loading document.
///@param controller The YLPDFViewController object informing the delegate.
///@param document The YLDocument object displayed by the controller.
- (void)pdfViewController:(YLPDFViewController *)controller didDisplayDocument:(YLDocument *)document;

/// Return YES if you want to override the default action for this annotation. The default value is NO.
///@param controller The YLPDFViewController object requesting this information.
///@param annotation The YLAnnotation object that was tapped on.
- (BOOL)pdfViewController:(YLPDFViewController *)controller tappedOnAnnotation:(YLAnnotation *)annotation;

@end
