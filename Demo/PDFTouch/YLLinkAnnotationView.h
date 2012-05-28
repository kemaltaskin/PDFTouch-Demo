//
//  YLLinkAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/16/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"

@protocol YLLinkAnnotationViewDelegate;

@interface YLLinkAnnotationView : UIView<YLAnnotationView> {
    UIColor *_borderColor;
    UIColor *_tapColor;
    CGFloat _borderRadius;
    
    NSObject<YLLinkAnnotationViewDelegate> *_delegate;
}

@property (nonatomic, retain) UIColor *borderColor;
@property (nonatomic, retain) UIColor *tapColor;
@property (nonatomic, assign) CGFloat borderRadius;
@property (nonatomic, assign) NSObject<YLLinkAnnotationViewDelegate> *delegate;

@end


@protocol YLLinkAnnotationViewDelegate <NSObject>
@required
- (void)linkAnnotationViewTapped:(YLLinkAnnotationView *)annotationView;
@end