//
//  MainViewController.m
//
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import "MainViewController.h"
#import "ChildViewController.h"
#import <PDFTouch/PDFTouch.h>

@interface MainViewController()<YLPDFViewControllerDelegate> {
    YLDocument *_document;
}

@property (nonatomic, readonly) YLDocument *document;

- (void)pushPDFView;
- (void)modalPDFView;
- (void)containmentPDFView;

@end

@implementation MainViewController

@synthesize document = _document;

- (id)initWithStyle:(UITableViewStyle)style {
    self = [super initWithStyle:style];
    if(self) {
        self.title = @"PDFTouch SDK Demo";
        
        self.navigationItem.backBarButtonItem = [[[UIBarButtonItem alloc] initWithTitle:@"Examples" style:UIBarButtonItemStyleDone target:nil action:nil] autorelease];
    }
    
    return self;
}

- (void)dealloc {
    [_document release];
    
    [super dealloc];
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self.navigationController setNavigationBarHidden:NO animated:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return YES;
}

- (YLDocument *)document {
    if(_document == nil) {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"Developers" ofType:@"pdf"];
        _document = [[YLDocument alloc] initWithFilePath:path];
        if(_document.isLocked) {
            // unlock pdf document
            [_document unlockWithPassword:@""];
        }
    }
    
    return _document;
}

#pragma mark -
#pragma mark UITableViewDataSource and UITableViewDelegate Methods
- (int)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (int)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if(section == 0) {
        return 3;
    }
    
    return 0;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    if(section == 0) {
        return @"Examples";
    }
    
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *CellIdentifier = @"CellIdentifier";
    
    UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if(cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier] autorelease];
    }
    
    if(indexPath.row == 0) {
        [[cell textLabel] setText:@"Push PDF ViewController"];
    } else if(indexPath.row == 1) {
        [[cell textLabel] setText:@"Open Modal PDF ViewController"];
    } else if(indexPath.row == 2) {
        [[cell textLabel] setText:@"Embed PDF ViewController"];
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if(indexPath.row == 0) {
        [self pushPDFView];
    } else if(indexPath.row == 1) {
        [self modalPDFView];
    } else if(indexPath.row == 2) {
        [self containmentPDFView];
    }
}


#pragma mark -
#pragma mark YLPDFViewControllerDelegate Methods
- (void)pdfViewController:(YLPDFViewController *)controller didDisplayDocument:(YLDocument *)document {
    NSLog(@"Did display document.");
}

- (void)pdfViewController:(YLPDFViewController *)controller willDismissDocument:(YLDocument *)document {
    NSLog(@"Will dismiss document.");
}

#pragma mark -
#pragma mark Private Methods
- (void)pushPDFView {
    YLPDFViewController *v = [[[YLPDFViewController alloc] initWithDocument:self.document] autorelease];
    [v setDelegate:self];
    [v setDocumentMode:YLDocumentModeDouble];
    [v setDocumentLead:YLDocumentLeadRight];
    [v setPageCurlEnabled:YES];
    [v setDismissButtonStyle:YLDismissButtonStyleBack];
    [v setDismissButtonText:@"Examples"];
    [self.navigationController pushViewController:v animated:YES];
}

- (void)modalPDFView {
    YLPDFViewController *v = [[[YLPDFViewController alloc] initWithDocument:self.document] autorelease];
    [v setDelegate:self];
    [v setDocumentMode:YLDocumentModeSingle];
    [v setPageCurlEnabled:YES];
    [v setDocumentLead:YLDocumentLeadRight];
    [v setModalPresentationStyle:UIModalPresentationFullScreen];
    [v setModalTransitionStyle:UIModalTransitionStyleCoverVertical];
    [self.navigationController presentViewController:v animated:YES completion:nil];
}

- (void)containmentPDFView {
    ChildViewController *c = [[[ChildViewController alloc] initWithDocument:self.document] autorelease];
    [self.navigationController pushViewController:c animated:YES];
}

@end