//
//  YLRenderingStateStack.h
//
//  Created by Kemal Taskin on 3/7/13.
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@class YLRenderingState;

@interface YLRenderingStateStack : NSObject

+ (YLRenderingStateStack *)stack;

- (YLRenderingState *)topRenderingState;
- (void)pushRenderingState:(YLRenderingState *)state;
- (YLRenderingState *)popRenderingState;

@end