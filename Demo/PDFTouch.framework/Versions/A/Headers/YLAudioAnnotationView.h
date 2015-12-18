//
//  YLAudioAnnotationView.h
//
//  Created by Kemal Taskin on 5/23/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"
#import <AVKit/AVKit.h>

/// View for displaying audio annotations.
@interface YLAudioAnnotationView : UIView<YLAnnotationView>

/// The AVPlayer used to play the audio file.
@property (nonatomic, readonly) AVPlayer *audioPlayer;

/// A Boolean value indicating wether audio playback should begin automatically.
@property (nonatomic, assign) BOOL autostart;

@end
