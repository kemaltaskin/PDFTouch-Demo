//
//  YLMapAnnotationView.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 8/23/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YLAnnotationView.h"
#import <MapKit/MapKit.h>

@interface YLMapAnnotationView : UIView<YLAnnotationView>

@property (nonatomic, readonly) MKMapView *mapView;

@end
