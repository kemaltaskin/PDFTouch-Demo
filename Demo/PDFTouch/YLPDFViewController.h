//
//  YLPDFViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/26/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YLDocument;
@protocol YLPDFViewControllerDelegate;

@interface YLPDFViewController : UIViewController {
    YLDocument *_document;
    NSUInteger _currentPage;
    
    NSObject<YLPDFViewControllerDelegate> *_delegate;
}

@property (nonatomic, retain) YLDocument *document;
@property (nonatomic, readonly) NSUInteger currentPage;
@property (nonatomic, assign) NSObject<YLPDFViewControllerDelegate> *delegate;

- (id)initWithDocument:(YLDocument *)document;

- (void)showToolbarsAnimated:(BOOL)animated;
- (void)hideToolbarsAnimated:(BOOL)animated;
- (void)toggleToolbarsAnimated:(BOOL)animated;

- (void)scrollToPage:(NSUInteger)page animated:(BOOL)animated;
- (void)scrollToNextPageAnimated:(BOOL)animated;
- (void)scrollToPreviousPageAnimated:(BOOL)animated;

- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated;

- (void)clearSearchResults;

@end
