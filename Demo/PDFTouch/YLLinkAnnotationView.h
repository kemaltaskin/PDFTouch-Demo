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

typedef enum {
    kLinkAnnotationViewTypeInvalid = 0,
    kLinkAnnotationViewTypeWeb,
    kLinkAnnotationViewTypeMail
} LinkAnnotationViewType;

/// View for displaying link annotations.
@interface YLLinkAnnotationView : UIView<YLAnnotationView>

/// Border color of the button representing the link annotation. Default color is [UIColor colorWithWhite:0.8 alpha:1.0].
@property (nonatomic, retain) UIColor *borderColor;

/// Highlight color of the button representing the link annotation. Default color is [UIColor colorWithWhite:0.2 alpha:0.5].
@property (nonatomic, retain) UIColor *tapColor;

/// Radius of the button representing the link annotation. Default value is 4.
@property (nonatomic, assign) CGFloat borderRadius;

/// Type of the link annotation view.
@property (nonatomic, readonly) LinkAnnotationViewType type;

/// Delegate to inform about tap events on the button representing the link annotation.
@property (nonatomic, assign) NSObject<YLLinkAnnotationViewDelegate> *delegate;

@end


/// Implement this delegate if you want to get notified when a link annotation is tapped.
@protocol YLLinkAnnotationViewDelegate <NSObject>
@required

/// Link annotation was tapped.
/// @param annotationView The YLLinkAnnotationView object representing the tapped annotation.
- (void)linkAnnotationViewTapped:(YLLinkAnnotationView *)annotationView;

@end