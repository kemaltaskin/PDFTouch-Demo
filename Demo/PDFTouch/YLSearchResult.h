//
//  YLSearchResult.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/2/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Selection;

/// Model object that holds information about a search result.
@interface YLSearchResult : NSObject 

/// Page number of the search result.
@property (nonatomic, readonly) NSUInteger page;

/// A short text containing the search term. This is used as context information when displaying the results.
@property (nonatomic, readonly) NSString *shortText;

/// Range of the search term in shortText.
@property (nonatomic, assign) NSRange boldRange;

/// Special object that holds information about the frame used to select the text on a PDF page.
@property (nonatomic, assign) Selection *selection;

/// Initializes a YLSearchResult object and returns it to the caller.
/// @returns An initialized YLSearchResult object.
/// @param page Page number of the search result.
/// @param text Short text that contains the search term.
- (id)initWithPage:(NSUInteger)page shortText:(NSString *)text;

@end
