//
//  YLWebViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/24/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YLWebViewController : UIViewController<UIWebViewDelegate>

@property (nonatomic, readonly) UIWebView *webView;

- (id)initWithURL:(NSURL *)url;

@end
