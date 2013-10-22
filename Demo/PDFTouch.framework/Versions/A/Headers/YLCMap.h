//
//  YLCMap.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

@interface YLCMap : NSObject

@property (nonatomic, copy) NSMutableArray *codeSpaceRanges;
@property (nonatomic, copy) NSMutableDictionary *characterMappings;
@property (nonatomic, copy) NSMutableDictionary *reverseCharacterMappings;

- (id)initWithPDFStream:(CGPDFStreamRef)stream;

- (id)initWithString:(NSString *)string;

- (NSNumber *)unicodeCharacter:(unichar)cid;
- (NSNumber *)cidCharacter:(unichar)unicode;

@end
