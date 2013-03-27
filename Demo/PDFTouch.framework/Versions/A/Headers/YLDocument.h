//
//  YLDocument.h
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YLPageInfo;
@class YLOutlineParser;
@class YLDocumentScanner;
@class YLAnnotationParser;

extern NSString *const kYLDocumentMetadataKeyTitle;
extern NSString *const kYLDocumentMetadataKeyAuthor;
extern NSString *const kYLDocumentMetadataKeySubject;
extern NSString *const kYLDocumentMetadataKeyKeywords;
extern NSString *const kYLDocumentMetadataKeyCreator;
extern NSString *const kYLDocumentMetadataKeyProducer;
extern NSString *const kYLDocumentMetadataKeyCreationDate;
extern NSString *const kYLDocumentMetadataKeyModDate;
extern NSString *const kYLDocumentMetadataKeyVersion;

/// Model object that represents the PDF file.
@interface YLDocument : NSObject

/// UUID string value that is used internally to construct file paths for the thumbnails and bookmarks.
/// Bookmarks are saved in Documents/Private Docs/Bookmarks/uuid.plist
/// All thumbnail images are saved to NSCachesDirectory/YLPDFKit/uuid/
@property (nonatomic, readonly) NSString *uuid;

/// Path of the PDF file.
@property (nonatomic, readonly) NSString *path;

/// Title of the PDF file. This is basically the filename minus the extension.
@property (nonatomic, copy) NSString *title;

/// Password to unlock the PDF file if it's encrypted.
@property (nonatomic, copy) NSString *password;

/// Boolean value that specifies wether the PDF file is locked or not. You can use this property to see if a PDF file is encrypted.
@property (nonatomic, assign, readonly, getter=isLocked) BOOL locked;

/// Boolean value that specifies if the document is a valid PDF file.
@property (nonatomic, readonly, getter=isValidPDF) BOOL validPDF;

/// Number of pages in the PDF file.
@property (nonatomic, readonly) NSUInteger pageCount;

/// Returns the outline parser for this document.
@property (nonatomic, readonly) YLOutlineParser *outlineParser;

/// Returns the scanner you can use to search for text in this document.
@property (nonatomic, readonly) YLDocumentScanner *scanner;

/// Returns the annotation parser.
@property (nonatomic, readonly) YLAnnotationParser *annotationParser;


/** @name Initialization Methods*/
/// Initializes a YLDocument instance and returns it to the caller.
/// @returns An initialized YLDocument instance.
/// @param path Filesystem path to the PDF file.
+ (YLDocument *)YLDocumentWithFilePath:(NSString *)path;

/// Initializes a YLDocument instance and returns it to the caller.
/// @returns An initialized YLDocument instance.
/// @param path Filesystem path to the PDF file.
- (id)initWithFilePath:(NSString *)path;


/** @name Encryption Methods*/
/// Use this function to unlock an encrypted PDF file.
/// @returns YES if successfully unlocked, otherwise NO.
/// @param password Password to use for unlocking the PDF file.
- (BOOL)unlockWithPassword:(NSString *)password;


/** @name Query Methods*/
/// Returns a YLPageInfo object for the requested page that holds information about the page rectangle and rotation. The YLPageInfo
/// is cached for future access.
/// @returns An initialized YLPageInfo object or nil when the page number is invalid.
/// @param page Page number starting from 0.
- (YLPageInfo *)pageInfoForPage:(NSUInteger)page;

/// Returns a CGPDF reference for this document. Retain this reference by using the CGPDFDocumentRetain method. When you're finished
/// using this reference you should release it with the CGPDFDocumentRelease function.
/// @returns A CGPDFDocumentRef instance.
- (CGPDFDocumentRef)requestDocumentRef;

/// Returns the requested metadata as NSString if there's any.
/// @returns A NSString value representing the metadata.
/// @param key NSString value. Use one of the predefined kYLDocumentMetadataKey* strings.
- (NSString *)metadataForKey:(NSString *)key;


/** @name Render Methods */
/// Renders a PDF page in the specified graphics context.
/// @param page Page number starting from 0.
/// @param targetRect The target rectangle the PDF page will be rendered in.
/// @param scale The scale at which the PDF page should be rendered.
/// @param context Graphics context.
- (void)renderPage:(NSUInteger)page targetRect:(CGRect)targetRect scale:(CGFloat)scale inContext:(CGContextRef)context;

/// Renders a PDF page in the specified graphics context. This function also highlights search results if there are any.
/// @param page Page number starting from 0.
/// @param targetRect The target rectangle the PDF page will be rendered in.
/// @param context Graphics context.
- (void)renderPage:(NSUInteger)page targetRect:(CGRect)targetRect inContext:(CGContextRef)context;


/** @name Bookmark Methods */
/// Adds bookmark for the requested page.
/// @returns YES if the bookmark is added, NO if the page is invalid.
/// @param page Page number starting from 0.
- (BOOL)addBookmarkForPage:(NSUInteger)page;

/// Removes bookmark for the requested page.
/// @returns YES if the bookmark is removed, NO if the page is invalid or if there was no bookmark to remove.
/// @param page Page number starting from 0.
- (BOOL)removeBookmarkForPage:(NSUInteger)page;

/// Use this function to query if there is a bookmark for a specific page.
/// @returns YES if there is a bookmark for this page.
/// @param page Page number starting from 0.
- (BOOL)hasBookmarkForPage:(NSUInteger)page;

/// Returns a sorted array of all bookmarked pages.
/// @returns Sorted NSArray with all bookmarked pages.
- (NSArray *)bookmarkedPageNumbers;

@end
