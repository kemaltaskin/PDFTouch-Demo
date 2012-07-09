//
//  YLSearchResult.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Selection;

@interface YLSearchResult : NSObject 

@property (nonatomic, readonly) NSUInteger page;
@property (nonatomic, readonly) NSString *shortText;
@property (nonatomic, assign) NSRange boldRange;
@property (nonatomic, assign) Selection *selection;

- (id)initWithPage:(NSUInteger)page shortText:(NSString *)text;

@end
