//
//  YLCMap.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@interface YLCMap : NSObject

- (id)initWithPDFStream:(CGPDFStreamRef)stream;

- (id)initWithString:(NSString *)string;

- (NSNumber *)unicodeCharacter:(unichar)cid;
- (NSNumber *)cidCharacter:(unichar)unicode;

@end
