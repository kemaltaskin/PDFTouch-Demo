//
//  YLScanner.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@interface YLScanner : NSObject

@property (nonatomic, readonly) NSMutableString *content;

+ (YLScanner *)scannerWithPage:(CGPDFPageRef)page;

- (NSArray *)select:(NSString *)keyword;

@end
