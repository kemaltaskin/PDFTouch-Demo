//
//  YLPageInfo.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/28/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YLPageInfo : NSObject {
    CGRect _origRect;
    CGRect _rotatedRect;
    int _rotation;
    NSUInteger _page;
}

@property (nonatomic, readonly) CGRect origRect;
@property (nonatomic, readonly) CGRect rotatedRect;
@property (nonatomic, readonly) int rotation;
@property (nonatomic, readonly) NSUInteger page;

+ (YLPageInfo *)YLPageInfoWithPage:(NSUInteger)page rect:(CGRect)rect rotation:(int)rotation;

- (id)initWithPage:(NSUInteger)page rect:(CGRect)rect rotation:(int)rotation;

@end
