//
//  ChildViewController.m
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import "ChildViewController.h"
#import <PDFTouch/PDFTouch.h>

@interface ChildViewController () {
    YLDocument *_document;
    YLPDFViewController *_pdfViewController;
}

@end

@implementation ChildViewController

- (id)initWithDocument:(YLDocument *)document {
    self = [super initWithNibName:nil bundle:nil];
    if(self) {
        _document = [document retain];
    }
    
    return self;
}

- (void)dealloc {
    [_document release];
    [_pdfViewController release];
    
    [super dealloc];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    _pdfViewController = [[YLPDFViewController alloc] initWithDocument:_document];
    [_pdfViewController setDocumentMode:YLDocumentModeSingle];
    [_pdfViewController setPageCurlEnabled:YES];
    [_pdfViewController setHideDismissButton:YES];
    [_pdfViewController setHideStatusBar:NO];
    
    [self addChildViewController:_pdfViewController];
    [_pdfViewController didMoveToParentViewController:self];
    CGRect frame = self.view.bounds;
    frame.origin.y += self.topLayoutGuide.length;
    frame.size.height -= self.topLayoutGuide.length;
    _pdfViewController.view.frame = frame;
    
    [self.view addSubview:_pdfViewController.view];
}

- (BOOL)prefersStatusBarHidden {
    return _pdfViewController.prefersStatusBarHidden;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
