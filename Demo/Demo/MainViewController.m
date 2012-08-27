//
//  MainViewController.m
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import "MainViewController.h"
#import "YLPDFViewController.h"
#import "YLDocument.h"

@interface MainViewController(Private)
- (void)viewTapped;
@end

@implementation MainViewController

@synthesize label = _label;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        self.title = @"PDFTouch SDK Demo";
    }
    
    return self;
}

- (void)dealloc {
    [_label release];
    
    [super dealloc];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UITapGestureRecognizer *t = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTapped)];
    [self.view addGestureRecognizer:t];
    [t release];
}

- (void)viewDidUnload {
    [super viewDidUnload];
    
    self.label = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return YES;
}


#pragma mark -
#pragma mark Private Methods
- (void)viewTapped {
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Developers" ofType:@"pdf"];
    YLDocument *document = [[[YLDocument alloc] initWithFilePath:path] autorelease];
    YLPDFViewController *v = [[YLPDFViewController alloc] initWithDocument:document];
    [v setDocumentMode:YLDocumentModeDouble];
    [v setPageCurlEnabled:YES];
    [v setDocumentLead:YLDocumentLeadRight];
    [v setAutoLayoutEnabled:YES];
    [v setModalPresentationStyle:UIModalPresentationFullScreen];
    [v setModalTransitionStyle:UIModalTransitionStyleCoverVertical];
    [self.navigationController presentModalViewController:v animated:YES];
    [v release];
}

@end
