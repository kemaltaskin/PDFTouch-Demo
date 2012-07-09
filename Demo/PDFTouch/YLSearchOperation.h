//
//  YLSearchOperation.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLDocument;
@protocol YLSearchDelegate;

@interface YLSearchOperation : NSOperation

@property (nonatomic, readonly) NSString *keyword;
@property (nonatomic, readonly) NSArray *searchResults;
@property (nonatomic, assign) NSObject<YLSearchDelegate> *delegate;

- (id)initWithDocument:(YLDocument *)document keyword:(NSString *)keyword;

- (NSArray *)searchResults;

@end


@protocol YLSearchDelegate <NSObject>
@required
- (void)searchOperation:(YLSearchOperation *)operation didUpdateResults:(NSArray *)results;
- (void)searchOperationFinished:(YLSearchOperation *)operation;
- (void)searchOperationCanceled:(YLSearchOperation *)operation;
@end
