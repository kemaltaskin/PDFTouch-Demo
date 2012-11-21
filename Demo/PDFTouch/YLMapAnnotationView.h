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

/// View for displaying map annotations.
@interface YLMapAnnotationView : UIView<YLAnnotationView>

/// The MKMapView object used to render the map.
@property (nonatomic, readonly) MKMapView *mapView;

@end
