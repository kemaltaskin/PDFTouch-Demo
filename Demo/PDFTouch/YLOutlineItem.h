//
//  YLOutlineItem.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Model object that represents a single outline item. These items are used while displaying the TOC of a PDF.
@interface YLOutlineItem : NSObject

/// Title of the outline item.
@property (nonatomic, retain) NSString *title;

/// Indentation level of the outline item.
@property (nonatomic, assign) NSUInteger indentation;

/// Page number of the outline item.
@property (nonatomic, assign) NSUInteger page;

/// Initializes a YLOutlineItem object and returns it to the caller.
/// @returns An initialized YLOutlineItem object.
/// @param title Title of the outline item.
/// @param indent Indentation level of the outline item.
/// @param page Page number of the outline item.
- (id)initWithTitle:(NSString *)title indentation:(NSUInteger)indent page:(NSUInteger)page;

@end
