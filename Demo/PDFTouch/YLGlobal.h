//
//  YLGlobal.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 4/5/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#ifndef YLPDFKit_YLGlobal_h
#define YLPDFKit_YLGlobal_h

#define SCROLLVIEW_CONTENT_PADDING      10.0
#define SCROLLVIEW_SHADOW_RADIUS        4.0
#define SCROLLVIEW_SHADOW_OFFSET        1.0
#define SCROLLVIEW_SHADOW_OPACITY       0.8

#define ZOOM_LEVELS                     4

#ifndef kCFCoreFoundationVersionNumber_iPhoneOS_5_0
#define kCFCoreFoundationVersionNumber_iPhoneOS_5_0 674.0
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 50000
#define IF_IOS5_OR_GREATER(...) \
if (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iPhoneOS_5_0) \
{ \
__VA_ARGS__ \
}
#else
#define IF_IOS5_OR_GREATER(...)
#endif

#endif
