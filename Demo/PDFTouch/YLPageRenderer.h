//
//  YLPageRenderer.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//
//  Copyright (c) 2011 Sorin Nistor. All rights reserved. This software is provided 'as-is', 
//  without any express or implied warranty. In no event will the authors be held liable for 
//  any damages arising from the use of this software. Permission is granted to anyone to 
//  use this software for any purpose, including commercial applications, and to alter it 
//  and redistribute it freely, subject to the following restrictions:
//  1. The origin of this software must not be misrepresented; you must not claim that you 
//  wrote the original software. If you use this software in a product, an acknowledgment 
//  in the product documentation would be appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be misrepresented 
//  as being the original software.
//  3. This notice may not be removed or altered from any source distribution.

#import <Foundation/Foundation.h>

@class YLPageInfo;

/// These are utility functions to render PDF pages in a graphics context.
@interface YLPageRenderer : NSObject

/// Renders a PDF page at a given point and specified zoom scale.
/// @param page Reference to the CGPDF page.
/// @param context Graphics context.
/// @param point Point defining the upper left coordinate where rendering should start.
/// @param zoom The scale at which the PDF page should be rendered.
/// @param pageInfo Page info object of this page.
/// @param searchResults Array of YLSearchResult items. Can be nil.
+ (void)renderPage:(CGPDFPageRef)page 
         inContext:(CGContextRef)context 
           atPoint:(CGPoint)point 
          withZoom:(float)zoom 
          pageInfo:(YLPageInfo *)pageInfo
            search:(NSArray *)searchResults;

/// Renders a PDF page in the specified rectangle.
/// @param page Reference to the CGPDF page.
/// @param context Graphics context.
/// @param rectangle The target rectangle the PDF page will be rendered in.
/// @param pageInfo Page info object of this page.
/// @param searchResults Array of YLSearchResult items. Can be nil.
+ (void)renderPage:(CGPDFPageRef)page 
         inContext:(CGContextRef)context 
       inRectangle:(CGRect)rectangle 
          pageInfo:(YLPageInfo *)pageInfo
            search:(NSArray *)searchResults;

@end
