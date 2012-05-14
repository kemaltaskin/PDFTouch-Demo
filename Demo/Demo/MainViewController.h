//
//  MainViewController.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 3/27/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MainViewController : UIViewController<UIGestureRecognizerDelegate> {
    UILabel *_label;
}

@property (nonatomic, retain) IBOutlet UILabel *label;

@end
