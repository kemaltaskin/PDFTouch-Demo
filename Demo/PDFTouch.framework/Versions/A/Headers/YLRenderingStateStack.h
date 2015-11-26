//
//  YLRenderingStateStack.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@class YLRenderingState;

@interface YLRenderingStateStack : NSObject

+ (YLRenderingStateStack *)stack;

- (YLRenderingState *)topRenderingState;
- (void)pushRenderingState:(YLRenderingState *)state;
- (YLRenderingState *)popRenderingState;

@end