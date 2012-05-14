//
//  AppDelegate.h
//  Demo
//
//  Created by Kemal Taskin on 5/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MainViewController;

@interface AppDelegate : UIResponder <UIApplicationDelegate> {
    MainViewController *_mainViewController;
    UINavigationController *_navController;
}

@property (strong, nonatomic) UIWindow *window;

@end
