//
//  YLPDFTouch.h
//  PDFTouchBinary
//
//  Created by Kemal Taskin on 03/11/14.
//  Copyright (c) 2014 Yakamoz Labs. All rights reserved.
//

@interface YLPDFTouch : NSObject

+ (instancetype)sharedInstance;

+ (NSString *)version;

+ (void)patchUIKit;

- (void)setLicenseKey:(NSString *)licenseKey;
- (NSString *)licenseKey;

@end
