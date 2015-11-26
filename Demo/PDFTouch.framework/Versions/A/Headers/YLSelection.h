//
//  YLSelection.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLRenderingState;

@interface YLSelection : NSObject

@property (nonatomic, readonly) NSArray *segments;

- (void)startWithState:(YLRenderingState *)state;
- (void)finalizeWithState:(YLRenderingState *)state;
- (void)reset;

@end


@interface YLSelectionSegment : NSObject

@property (nonatomic, readonly) CGRect frame;
@property (nonatomic, readonly) CGAffineTransform transform;
@property (nonatomic, copy) YLRenderingState *startState;

+ (YLSelectionSegment *)segmentWithStartState:(YLRenderingState *)state;

- (id)initWithStartState:(YLRenderingState *)state;

- (void)finalizeWithState:(YLRenderingState *)state;


@end
