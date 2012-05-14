//
//  YLOutlineParser.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 5/1/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLDocument;

@interface YLOutlineParser : NSObject {
    YLDocument *_document;
}

- (id)initWithDocument:(YLDocument *)document;

- (void)parse;
- (NSArray *)outline;

@end
