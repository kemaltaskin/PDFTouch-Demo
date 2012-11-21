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

/// This operation will search for text in the PDF file.
@interface YLSearchOperation : NSOperation

/// The search term.
@property (nonatomic, readonly) NSString *keyword;

/// Array with YLSearchResult items.
@property (nonatomic, readonly) NSArray *searchResults;

/// Reference to the delegate that should be informed.
@property (nonatomic, assign) NSObject<YLSearchDelegate> *delegate;


/** @name Initialization */
/// Initializes a YLSearchOperation instance and returns it to the caller.
/// @returns An initialized YLSearchOperation instance.
/// @param document Reference to the document
/// @param keyword Text that should be searched for.
- (id)initWithDocument:(YLDocument *)document keyword:(NSString *)keyword;

@end


/// Implement this protocol to stay informed about the search operation.
@protocol YLSearchDelegate <NSObject>
@required
///
/// @param operation The YLSearchOperation object informing the delegate.
- (void)searchOperation:(YLSearchOperation *)operation didUpdateResults:(NSArray *)results;

///
/// @param operation The YLSearchOperation object informing the delegate.
- (void)searchOperationFinished:(YLSearchOperation *)operation;

///
/// @param operation The YLSearchOperation object informing the delegate.
- (void)searchOperationCanceled:(YLSearchOperation *)operation;
@end
