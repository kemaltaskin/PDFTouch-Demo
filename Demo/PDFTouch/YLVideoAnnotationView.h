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

/// View for displaying video annotations.
@interface YLVideoAnnotationView : UIView<YLAnnotationView>

/// Reference to the MPMoviePlayerController object used for playing the video.
@property (nonatomic, readonly) MPMoviePlayerController *moviePlayer;

/// A Boolean that indicates wether the movie should begin playback automatically.
@property (nonatomic, assign) BOOL autostart;

@end
