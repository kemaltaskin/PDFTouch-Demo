//
//  YLOutlineParser.h
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLDocument;
@protocol YLOutlineParserDelegate;

/// YLOutlineParser is responsible for parsing the TOC of a PDF file.
@interface YLOutlineParser : NSObject

@property (nonatomic, assign) NSObject<YLOutlineParserDelegate> *delegate;

/** @name Initialization */
/// Initializes a YLOutlineParser instance and returns it to the caller.
/// @returns An initialized YLOutlineParser instance.
/// @param document Reference to the document.
- (id)initWithDocument:(YLDocument *)document;

/** @name Helper Methods */
/// Parse the TOC of the PDF file.
- (void)parse;

/// Cancel parsing of TOC.
- (void)cancel;

/// Returns an array with YLOutlineItem objects. This method will return nil if
/// parsing is not finished yet or when there's no outline available.
- (NSArray *)outline;

@end


@protocol YLOutlineParserDelegate <NSObject>
@required
- (void)outlineParsed:(YLOutlineParser *)parser;
@end
