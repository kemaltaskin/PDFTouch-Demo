//
//  YLPDFViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLDocument;

@interface YLPDFViewController : UIViewController {
    YLDocument *_document;
    NSUInteger _currentPage;
}

@property (nonatomic, retain) YLDocument *document;
@property (nonatomic, readonly) NSUInteger currentPage;

- (id)initWithDocument:(YLDocument *)document;

- (void)showToolbarsAnimated:(BOOL)animated;
- (void)hideToolbarsAnimated:(BOOL)animated;
- (void)toggleToolbarsAnimated:(BOOL)animated;

- (void)scrollToPage:(NSUInteger)page animated:(BOOL)animated;
- (void)scrollToNextPageAnimated:(BOOL)animated;
- (void)scrollToPreviousPageAnimated:(BOOL)animated;

@end
