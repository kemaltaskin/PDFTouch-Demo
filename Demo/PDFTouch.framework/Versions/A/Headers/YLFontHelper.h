//
//  YLFontHelper.h
//
//  Created by Kemal Taskin on 2/26/13.
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@class YLCMap;

@interface YLFontHelper : NSObject

+ (YLFontHelper *)sharedInstance;

- (YLCMap *)cmapWithRegistry:(NSString *)registry ordering:(NSString *)ordering;

- (NSNumber *)unicodeForName:(NSString *)name;

- (NSString *)ligatureForCharacter:(unichar)character;

- (NSString *)coreTextFontNameForFont:(NSString *)name standardFont:(BOOL *)standardFont;

@end
