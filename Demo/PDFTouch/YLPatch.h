//
//  YLPatch.h
//  YLPDFKit
//
//  Created by Kemal Taskin on 6/28/12.
//  Copyright (c) 2012 Yakamoz Labs. All rights reserved.
//

#ifndef YLPDFKit_YLPatch_h
#define YLPDFKit_YLPatch_h

#import <objc/runtime.h> 
#import <objc/message.h>

// Fixes crashes in UIPageViewController
// https://gist.github.com/1788910
// Thanks Peter Steinberger!
void Swizzle(Class c, SEL orig, SEL new);
void Swizzle(Class c, SEL orig, SEL new) {
    Method origMethod = class_getInstanceMethod(c, orig);
    Method newMethod = class_getInstanceMethod(c, new);
    if(class_addMethod(c, orig, method_getImplementation(newMethod), method_getTypeEncoding(newMethod))) {
        class_replaceMethod(c, new, method_getImplementation(origMethod), method_getTypeEncoding(origMethod));
    } else {
        method_exchangeImplementations(origMethod, newMethod);
    }
}

void customDealloc(id this, SEL this_cmd);
void customDealloc(id this, SEL this_cmd) {    
    __block id weakThis = this;
    double delayInSeconds = 2.0;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void) {
        [weakThis performSelector:NSSelectorFromString(@"customDealloc")];
    });
}

void patchUIKit();
void patchUIKit() {
    // _UIPageCurlState
    Class pagecurlstate = NSClassFromString([NSString stringWithFormat:@"_%@Cu%@ate", @"UIPage", @"rlSt"]);
    class_addMethod(pagecurlstate, @selector(customDealloc), (IMP)customDealloc, "");
    Swizzle(pagecurlstate, NSSelectorFromString(@"dealloc"), @selector(customDealloc));    
    
    // [_UIPageCurl _pageCurlAnimationDidStop:withState:]: message sent to deallocated instance
    Class pagecurl = NSClassFromString([NSString stringWithFormat:@"_%@Cu%@", @"UIPage", @"rl"]);
    class_addMethod(pagecurl, @selector(customDealloc), (IMP)customDealloc, "");
    Swizzle(pagecurl, NSSelectorFromString(@"dealloc"), @selector(customDealloc));    
}

#endif
