//
//  SVGAVideoSpriteEntity.h
//  SVGAPlayer
//
//  Created by 崔明辉 on 2017/2/20.
//  Copyright © 2017年 UED Center. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

@class SVGAVideoSpriteFrameEntity, SVGAContentLayer;
@class SVGAProtoSpriteEntity;

@interface SVGAVideoSpriteEntity : NSObject

@property (nonatomic, readonly) NSString *imageKey;
@property (nonatomic, readonly) NSArray<SVGAVideoSpriteFrameEntity *> *frames;
@property (nonatomic, readonly) NSString *matteKey;

- (instancetype)initWithJSONObject:(NSDictionary *)JSONObject;
- (instancetype)initWithProtoObject:(SVGAProtoSpriteEntity *)protoObject;

- (SVGAContentLayer *)requestLayerWithBitmap:(UIImage *)bitmap;

@end
