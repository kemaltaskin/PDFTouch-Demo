//
//  YLWebViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/24/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

/// This view controller is used to display web pages for modal YLWebAnnotationView annotation views.
@interface YLWebViewController : UIViewController<UIWebViewDelegate>

/// Reference to the UIWebView object.
@property (nonatomic, readonly) UIWebView *webView;

/// Initializes a YLWebViewController and returns it to the caller.
/// @returns An initialized YLWebViewController object.
/// @param url Url of the web page that should be displayed.
- (id)initWithURL:(NSURL *)url;

@end
