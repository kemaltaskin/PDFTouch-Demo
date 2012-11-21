//
//  YLAudioAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/23/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"
#import <MediaPlayer/MediaPlayer.h>

/// View for displaying audio annotations.
@interface YLAudioAnnotationView : UIView<YLAnnotationView>

/// The MPMoviePlayerController used to play the audio file.
@property (nonatomic, readonly) MPMoviePlayerController *audioPlayer;

/// A Boolean value indicating wether audio playback should begin automatically.
@property (nonatomic, assign) BOOL autostart;

@end
