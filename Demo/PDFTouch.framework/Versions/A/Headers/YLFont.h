//
//  YLFont.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import "YLFontDescriptor.h"
#import "YLCMap.h"

extern const char *kPDFFontDescriptorKey;
extern const char *kPDFFontKey;
extern const char *kPDFFontTypeKey;
extern const char *kPDFFontSubtypeKey;
extern const char *kPDFDescendantFontsKey;
extern const char *kPDFBaseFontKey;
extern const char *kPDFFirstCharKey;
extern const char *kPDFLastCharKey;
extern const char *kPDFWidthsKey;
extern const char *kPDFEncodingKey;
extern const char *kPDFBaseEncodingKey;
extern const char *kPDFEncodingDifferencesKey;
extern const char *kPDFToUnicodeKey;
extern const char *kPDFFontFileKey;
extern const char *kPDFFontFile2Key;
extern const char *kPDFFontFile3Key;


@interface YLFont : NSObject

@property (nonatomic, readonly) NSString *type;
@property (nonatomic, readonly) NSString *baseFont;

@property (nonatomic, retain) YLCMap *cmap;
@property (nonatomic, readonly) YLFontDescriptor *fontDescriptor;
@property (nonatomic, readonly) NSMutableDictionary *widths;
@property (nonatomic, readonly) NSStringEncoding encoding;

@property (nonatomic, readonly) CGFloat minY;
@property (nonatomic, readonly) CGFloat maxY;


+ (YLFont *)fontWithDictionary:(CGPDFDictionaryRef)dict;

- (id)initWithFontDictionary:(CGPDFDictionaryRef)dict;

- (void)setWidthsWithFontDictionary:(CGPDFDictionaryRef)dict;
- (void)setToUnicodeWithFontDictionary:(CGPDFDictionaryRef)dict;

- (NSString *)stringWithPDFString:(CGPDFStringRef)pdfString ligatures:(BOOL *)ligatures;

- (NSNumber *)cidCharacter:(unichar)character;

- (CGFloat)widthOfCharacter:(unichar)characher withFontSize:(CGFloat)fontSize;
- (CGFloat)widthOfSpaceWithFontSize:(CGFloat)fontSize;
- (BOOL)isSpaceCharacter:(unichar)character;

@end
