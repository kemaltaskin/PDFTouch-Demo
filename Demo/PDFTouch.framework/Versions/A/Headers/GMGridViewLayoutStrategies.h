//
//  GMGridViewLayoutStrategy.h
//  GMGridView
//
//  Created by Gulam Moledina on 11-10-28.
//  Copyright (c) 2011 GMoledina.ca. All rights reserved.
//
//  Latest code can be found on GitHub: https://github.com/gmoledina/GMGridView
// 
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
// 
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define GMGV_INVALID_POSITION -1

@protocol YLGMGridViewLayoutStrategy;


typedef enum {
    YLGMGridViewLayoutVertical = 0,
    YLGMGridViewLayoutHorizontal,
    YLGMGridViewLayoutHorizontalPagedLTR,   // LTR: left to right
    YLGMGridViewLayoutHorizontalPagedTTB    // TTB: top to bottom
} YLGMGridViewLayoutStrategyType;



//////////////////////////////////////////////////////////////
#pragma mark - Strategy Factory
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutStrategyFactory : NSObject

+ (id<YLGMGridViewLayoutStrategy>)strategyFromType:(YLGMGridViewLayoutStrategyType)type;

@end


//////////////////////////////////////////////////////////////
#pragma mark - The strategy protocol
//////////////////////////////////////////////////////////////

@protocol YLGMGridViewLayoutStrategy <NSObject>

+ (BOOL)requiresEnablingPaging;

- (YLGMGridViewLayoutStrategyType)type;

// Setup
- (void)setupItemSize:(CGSize)itemSize andItemSpacing:(NSInteger)spacing withMinEdgeInsets:(UIEdgeInsets)edgeInsets andCenteredGrid:(BOOL)centered;

// Recomputing
- (void)rebaseWithItemCount:(NSInteger)count insideOfBounds:(CGRect)bounds;

// Fetching the results
- (CGSize)contentSize;
- (CGPoint)originForItemAtPosition:(NSInteger)position;
- (NSInteger)itemPositionFromLocation:(CGPoint)location;

- (NSRange)rangeOfPositionsInBoundsFromOffset:(CGPoint)offset;

@end


//////////////////////////////////////////////////////////////
#pragma mark - Strategy Base class
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutStrategyBase : NSObject
{
    @protected
    // All of these vars should be set in the init method
    YLGMGridViewLayoutStrategyType _type;
    
    // All of these vars should be set in the setup method of the child class
    CGSize _itemSize;
    NSInteger _itemSpacing;
    UIEdgeInsets _minEdgeInsets;
    BOOL _centeredGrid;
    
    // All of these vars should be set in the rebase method of the child class
    NSInteger _itemCount;
    UIEdgeInsets _edgeInsets;
    CGRect _gridBounds;
    CGSize _contentSize;
}

@property (nonatomic, readonly) YLGMGridViewLayoutStrategyType type;

@property (nonatomic, readonly) CGSize itemSize;
@property (nonatomic, readonly) NSInteger itemSpacing;
@property (nonatomic, readonly) UIEdgeInsets minEdgeInsets;
@property (nonatomic, readonly) BOOL centeredGrid;

@property (nonatomic, readonly) NSInteger itemCount;
@property (nonatomic, readonly) UIEdgeInsets edgeInsets;
@property (nonatomic, readonly) CGRect gridBounds;
@property (nonatomic, readonly) CGSize contentSize;

// Protocol methods implemented in base class
- (void)setupItemSize:(CGSize)itemSize andItemSpacing:(NSInteger)spacing withMinEdgeInsets:(UIEdgeInsets)edgeInsets andCenteredGrid:(BOOL)centered;

// Helpers
- (void)setEdgeAndContentSizeFromAbsoluteContentSize:(CGSize)actualContentSize;

@end

//////////////////////////////////////////////////////////////
#pragma mark - Vertical strategy
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutVerticalStrategy : YLGMGridViewLayoutStrategyBase <YLGMGridViewLayoutStrategy>
{
    @protected
    NSInteger _numberOfItemsPerRow;
}

@property (nonatomic, readonly) NSInteger numberOfItemsPerRow;

@end

//////////////////////////////////////////////////////////////
#pragma mark - Horizontal strategy
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutHorizontalStrategy : YLGMGridViewLayoutStrategyBase <YLGMGridViewLayoutStrategy>
{
    @protected
    NSInteger _numberOfItemsPerColumn;
}

@property (nonatomic, readonly) NSInteger numberOfItemsPerColumn;

@end


//////////////////////////////////////////////////////////////
#pragma mark - Horizontal Paged strategy (LTR behavior)
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutHorizontalPagedStrategy : YLGMGridViewLayoutHorizontalStrategy
{
    @protected
    NSInteger _numberOfItemsPerRow;
    NSInteger _numberOfItemsPerPage;
    NSInteger _numberOfPages;
}

@property (nonatomic, readonly) NSInteger numberOfItemsPerRow;
@property (nonatomic, readonly) NSInteger numberOfItemsPerPage;
@property (nonatomic, readonly) NSInteger numberOfPages;


// Only these 3 methods have be reimplemented by child classes to change the LTR and TTB kind of behavior
- (NSInteger)positionForItemAtColumn:(NSInteger)column row:(NSInteger)row page:(NSInteger)page;
- (NSInteger)columnForItemAtPosition:(NSInteger)position;
- (NSInteger)rowForItemAtPosition:(NSInteger)position;

@end


//////////////////////////////////////////////////////////////
#pragma mark - Horizontal Paged Left to Right strategy
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutHorizontalPagedLTRStrategy : YLGMGridViewLayoutHorizontalPagedStrategy

@end

//////////////////////////////////////////////////////////////
#pragma mark - Horizontal Paged Top To Bottom strategy
//////////////////////////////////////////////////////////////

@interface YLGMGridViewLayoutHorizontalPagedTTBStrategy : YLGMGridViewLayoutHorizontalPagedStrategy

@end