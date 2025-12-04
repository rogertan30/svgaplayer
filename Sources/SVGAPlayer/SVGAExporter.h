//
//  SVGAExporter.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 2017/3/7.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

@class SVGAVideoEntity;

@interface SVGAExporter : NSObject

@property (nonatomic, strong) SVGAVideoEntity *videoItem;

- (NSArray<UIImage *> *)toImages;

- (void)saveImages:(NSString *)toPath filePrefix:(NSString *)filePrefix;

@end
