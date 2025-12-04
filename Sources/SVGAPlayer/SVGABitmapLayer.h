//
//  SVGABitmapLayer.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 2017/2/20.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

@class SVGAVideoSpriteFrameEntity;

@interface SVGABitmapLayer : CALayer

- (instancetype)initWithFrames:(NSArray<SVGAVideoSpriteFrameEntity *> *)frames;

- (void)stepToFrame:(NSInteger)frame;

@end
