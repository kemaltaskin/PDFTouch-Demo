//
//  YLWebAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/23/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"

@interface YLWebAnnotationView : UIView<YLAnnotationView>

@property (nonatomic, readonly) UIWebView *webView;

@end
