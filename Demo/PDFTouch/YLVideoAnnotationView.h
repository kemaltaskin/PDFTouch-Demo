//
//  YLVideoAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/23/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"
#import <MediaPlayer/MediaPlayer.h>

@interface YLVideoAnnotationView : UIView<YLAnnotationView>

@property (nonatomic, readonly) MPMoviePlayerController *moviePlayer;
@property (nonatomic, assign) BOOL autostart;

@end