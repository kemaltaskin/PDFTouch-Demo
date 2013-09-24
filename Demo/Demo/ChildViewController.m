//
//  ChildViewController.m
//
//  Copyright (c) 2013 Yakamoz Labs. All rights reserved.
//

#import "ChildViewController.h"
#import <PDFTouch/PDFTouch.h>

@interface ChildViewController () {
    YLDocument *_document;
}

@end

@implementation ChildViewController

- (id)initWithDocument:(YLDocument *)document {
    self = [super initWithNibName:nil bundle:nil];
    if(self) {
        self.title = @"Embed PDF ViewController";
        
        _document = [document retain];
    }
    
    return self;
}

- (void)dealloc {
    [_document release];
    [super dealloc];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 70000
    IF_IOS7_OR_GREATER
    (
     self.edgesForExtendedLayout = UIRectEdgeNone;
     )
#endif
    
    YLPDFViewController *v = [[[YLPDFViewController alloc] initWithDocument:_document] autorelease];
    [v setDocumentMode:YLDocumentModeSingle];
    [v setPageCurlEnabled:YES];
    [v setHideDismissButton:YES];
    [v setHideNavigationBar:NO];
    
    [self addChildViewController:v];
    [v didMoveToParentViewController:self];
    CGRect frame = self.view.bounds;
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 70000
    IF_IOS7_OR_GREATER
    (
     frame.origin.y += self.topLayoutGuide.length;
     frame.size.height -= self.topLayoutGuide.length;
     )
#endif
    v.view.frame = frame;
    
    [self.view addSubview:v.view];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
