//
//  YLFontCollection.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import "YLFont.h"

@interface YLFontCollection : NSObject

- (id)initWithFontDictionary:(CGPDFDictionaryRef)dict;

- (YLFont *)fontNamed:(NSString *)fontName;
- (NSDictionary *)fonts;

@end
