//
//  SVGABezierPath.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 16/6/28.
//  Copyright © 2016年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

@interface SVGABezierPath : UIBezierPath

- (void)setValues:(nonnull NSString *)values;

- (nonnull CAShapeLayer *)createLayer;

@end
