//
//  YLOutlineItem.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YLOutlineItem : NSObject {
    NSString *_title;
    NSUInteger _indentation;
    NSUInteger _page;
}

@property (nonatomic, retain) NSString *title;
@property (nonatomic, assign) NSUInteger indentation;
@property (nonatomic, assign) NSUInteger page;

- (id)initWithTitle:(NSString *)title indentation:(NSUInteger)indent page:(NSUInteger)page;

@end
