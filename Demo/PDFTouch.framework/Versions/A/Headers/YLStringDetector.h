//
//  YLStringDetector.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

/**
 * A detector implementing a finite state machine with the goal of detecting a predefined keyword in a continuous stream
 * of characters. The user of a detector can append strings, and will receive a number of messages reflecting the
 * current state of the detector.
 */

#import "YLFont.h"
#import "YLStringDetectorDelegate.h"

@interface YLStringDetector : NSObject

@property (nonatomic, retain) NSMutableString *unicodeContent;
@property (nonatomic, assign) id<YLStringDetectorDelegate> delegate;

+ (YLStringDetector *)detectorWithKeyword:(NSString *)keyword delegate:(id<YLStringDetectorDelegate>)delegate;

- (id)initWithKeyword:(NSString *)keyword;

- (void)reset;

- (NSString *)appendPDFString:(CGPDFStringRef)string withFont:(YLFont *)font;

@end
