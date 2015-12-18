//
//  YLScanner.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import "YLStringDetectorDelegate.h"

@interface YLScanner : NSObject<YLStringDetectorDelegate>

@property (nonatomic, readonly) NSMutableString *content;

+ (YLScanner *)scannerWithPage:(CGPDFPageRef)page;

- (NSArray *)select:(NSString *)keyword;

- (void)setHorizontalScale:(CGPDFScannerRef)scanner;
- (void)setTextLeading:(CGPDFScannerRef)scanner;
- (void)setFont:(CGPDFScannerRef)scanner;
- (void)setTextRise:(CGPDFScannerRef)scanner;
- (void)setCharacterSpacing:(CGPDFScannerRef)scanner;
- (void)setWordSpacing:(CGPDFScannerRef)scanner;

- (void)setNewLine:(CGPDFScannerRef)scanner;
- (void)setNewLine:(CGPDFScannerRef)scanner andSaveLeading:(BOOL)saveLeading;
- (void)setNewParagraph:(CGPDFScannerRef)scanner;
- (void)setTextMatrix:(CGPDFScannerRef)scanner;

- (void)printString:(CGPDFScannerRef)scanner;
- (void)printStringWithNewLine:(CGPDFScannerRef)scanner;
- (void)printStringWithNewLineAndSetSpacing:(CGPDFScannerRef)scanner;
- (void)printStringsAndSpaces:(CGPDFScannerRef)scanner;

- (void)pushRenderingState:(CGPDFScannerRef)scanner;
- (void)popRenderingState:(CGPDFScannerRef)scanner;
- (void)applyTransformation:(CGPDFScannerRef)scanner;

@end
