//
//  YLWebAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/23/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"

/// View for displaying web annotations.
@interface YLWebAnnotationView : UIView<YLAnnotationView>

/// The UIWebView object used to display the web page.
@property (nonatomic, readonly) UIWebView *webView;

@end
