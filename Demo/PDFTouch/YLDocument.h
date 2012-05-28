//
//  YLDocument.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLPageInfo;
@class YLOutlineParser;
@class YLDocumentScanner;
@class YLAnnotationParser;

@interface YLDocument : NSObject {
    NSString *_uuid;
    NSString *_title;
    NSString *_password;
    
    NSURL *_fileURL;
    
    CGPDFDocumentRef _documentRef;
    NSUInteger _pageCount;
}

@property (nonatomic, readonly) NSString *uuid;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, assign, readonly, getter=isLocked) BOOL locked;
@property (nonatomic, readonly) NSUInteger pageCount;
@property (nonatomic, readonly) YLOutlineParser *outlineParser;
@property (nonatomic, readonly) YLDocumentScanner *scanner;
@property (nonatomic, readonly) YLAnnotationParser *annotationParser;


+ (YLDocument *)YLDocumentWithURL:(NSURL *)url;

- (id)initWithURL:(NSURL *)url;

- (BOOL)unlockWithPassword:(NSString *)password;
- (YLPageInfo *)pageInfoForPage:(NSUInteger)page;
- (CGPDFDocumentRef)requestDocumentRef;

@end
