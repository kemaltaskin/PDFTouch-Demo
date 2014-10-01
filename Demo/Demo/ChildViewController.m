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
    
    self.edgesForExtendedLayout = UIRectEdgeNone;

    YLPDFViewController *v = [[[YLPDFViewController alloc] initWithDocument:_document] autorelease];
    [v setDocumentMode:YLDocumentModeSingle];
    [v setPageCurlEnabled:YES];
    [v setHideDismissButton:YES];
    [v setHideNavigationBar:NO];
    
    [self addChildViewController:v];
    [v didMoveToParentViewController:self];
    CGRect frame = self.view.bounds;
    frame.origin.y += self.topLayoutGuide.length;
    frame.size.height -= self.topLayoutGuide.length;
    v.view.frame = frame;
    
    [self.view addSubview:v.view];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
