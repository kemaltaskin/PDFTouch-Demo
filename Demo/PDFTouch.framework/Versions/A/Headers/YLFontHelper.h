//
//  YLFontHelper.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@class YLCMap;
@class YLFont;

@interface YLFontHelper : NSObject

+ (YLFontHelper *)sharedInstance;

- (YLCMap *)cmapWithRegistry:(NSString *)registry ordering:(NSString *)ordering;

- (NSNumber *)unicodeForName:(NSString *)name;

- (NSString *)ligatureForCharacter:(unichar)character;

- (NSString *)coreTextFontNameForFont:(NSString *)name standardFont:(BOOL *)standardFont;

- (CGFloat)minYForFontName:(NSString *)name;

- (CGFloat)maxYForFontName:(NSString *)name;

- (NSNumber *)widthForFontName:(NSString *)name character:(unichar)character;

- (void)setWidth:(CGFloat)width forFontName:(NSString *)name character:(unichar)character;

- (YLFont *)fontWithKey:(NSString *)key;

- (void)setFont:(YLFont *)font key:(NSString *)key;

- (void)clearCache;

@end
