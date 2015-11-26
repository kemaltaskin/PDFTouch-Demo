//
//  YLStringDetector.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@class YLStringDetector;

@protocol YLStringDetectorDelegate<NSObject>
@required
- (void)detectorDidStartMatching:(YLStringDetector *)stringDetector;
- (void)detectorFoundString:(YLStringDetector *)detector;
- (void)detector:(YLStringDetector *)detector didScanCharacter:(unichar)character;
@end
