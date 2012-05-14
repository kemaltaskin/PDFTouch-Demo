//
//  YLDocumentScanner.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YLSearchOperation.h"

@class YLDocument;

@interface YLDocumentScanner : NSObject {
    YLDocument *_document;
    
    NSString *_lastSearchText;
    NSArray *_searchResults;
    
    NSObject<YLSearchDelegate> *_delegate;
}

@property (nonatomic, readonly) NSString *lastSearchText;
@property (nonatomic, retain) NSArray *searchResults;
@property (nonatomic, assign) NSObject<YLSearchDelegate> *searchDelegate;

- (id)initWithDocument:(YLDocument *)document;

- (void)searchText:(NSString *)text;
- (NSArray *)searchResultsForPage:(NSUInteger)page;

- (void)cancelSearch;

@end
