//
//  YLOutlineParser.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLDocument;

/// YLOutlineParser is responsible for parsing the TOC of a PDF file.
@interface YLOutlineParser : NSObject

/** @name Initialization */
/// Initializes a YLOutlineParser instance and returns it to the caller.
/// @returns An initialized YLOutlineParser instance.
/// @param document Reference to the document.
- (id)initWithDocument:(YLDocument *)document;

/** @name Helper Methods */
/// Parse the TOC of the PDF file.
- (void)parse;

/// Returns an array with YLOutlineItem objects. This method will return nil if parsing is not finished yet.
- (NSArray *)outline;

@end
