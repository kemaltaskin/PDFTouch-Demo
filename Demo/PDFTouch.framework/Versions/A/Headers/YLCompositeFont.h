//
//  YLCompositeFont.h
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

/*
 *	A composite font is one of the following types:
 *		- Type0
 *		- CIDType0Font
 *		- CIDType2Font
 *
 *	Composite fonts have the following specific traits:
 *		- Default glyph width
 *
 */

#import "YLFont.h"

@interface YLCompositeFont : YLFont

@property (nonatomic, readonly) CGFloat defaultWidth;

@end
