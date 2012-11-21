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

/// YLDocumentScanner is responsible for searching the PDF file.
@interface YLDocumentScanner : NSObject

/// Returns the last used search term.
@property (nonatomic, readonly) NSString *lastSearchText;

/// Returns an array with YLSearchResult objects. You can also set this property to nil if you want to
/// remove the previous search results.
@property (nonatomic, retain) NSArray *searchResults;

/// Reference to the delegate.
@property (nonatomic, assign) NSObject<YLSearchDelegate> *searchDelegate;


/** @name Initialization */
/// Initializes a YLDocumentScanner instance and returns it to the caller.
/// @returns An initialized YLDocumentScanner instance
/// @param document Reference to the document.
- (id)initWithDocument:(YLDocument *)document;

/** Search Methods */
/// Use this method to search for text. This function will start an async search operation and will
/// inform the caller via the delegate.
/// @param text The text to search for.
- (void)searchText:(NSString *)text;

/// Returns the search results for a specific page.
/// @returns An array with YLSearchResult objects.
/// @param page Page number starting from 0.
- (NSArray *)searchResultsForPage:(NSUInteger)page;

/// Cancels the ongoing search operation if any.
- (void)cancelSearch;

@end
