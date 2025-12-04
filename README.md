# SVGAPlayer Swift Package Manager

这是一个基于 [SVGAPlayer-iOS](https://github.com/svga/SVGAPlayer-iOS) 的 Swift Package Manager 版本，提供了与原库完全相同的 API 接口。

## 功能特性

- ✅ 完全兼容原 SVGAPlayer-iOS API
- ✅ 支持 Swift Package Manager
- ✅ 支持 iOS 12.0+
- ✅ 包含所有公共类和方法
- ✅ 支持动态对象替换
- ✅ 支持音频播放
- ✅ 支持缓存机制

## 安装

### Swift Package Manager

在 Xcode 中，选择 File → Add Package Dependencies，然后输入此仓库的 URL：

```
https://github.com/your-username/SVGAPlayer-SPM
```

或者直接在 `Package.swift` 中添加依赖：

```swift
dependencies: [
    .package(url: "https://github.com/your-username/SVGAPlayer-SPM", from: "1.0.0")
]
```

## 使用方法

### 基本使用

```swift
import SVGAPlayer

class ViewController: UIViewController {
    @IBOutlet weak var playerView: SVGAPlayer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupSVGAPlayer()
    }
    
    func setupSVGAPlayer() {
        // 创建解析器
        let parser = SVGAParser()
        
        // 从网络加载
        parser.parseWithURL(URL(string: "https://example.com/animation.svga")!) { videoItem in
            DispatchQueue.main.async {
                if let videoItem = videoItem {
                    self.playerView.videoItem = videoItem
                    self.playerView.startAnimation()
                }
            }
        } failureBlock: { error in
            print("加载失败: \(error?.localizedDescription ?? "未知错误")")
        }
    }
}
```

### 使用 SVGAImageView

```swift
import SVGAPlayer

class ViewController: UIViewController {
    @IBOutlet weak var imageView: SVGAImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // 设置自动播放和动画名称
        imageView.autoPlay = true
        imageView.imageName = "animation"
    }
}
```

### 动态对象替换

```swift
// 替换图片
playerView.setImage(UIImage(named: "newImage"), forKey: "imageKey")

// 替换文本
let attributedText = NSAttributedString(string: "动态文本")
playerView.setAttributedText(attributedText, forKey: "textKey")

// 隐藏元素
playerView.setHidden(true, forKey: "elementKey")

// 自定义绘制
playerView.setDrawingBlock { contentLayer, frameIndex in
    // 自定义绘制逻辑
} forKey: "customKey"
```

### 代理方法

```swift
extension ViewController: SVGAPlayerDelegate {
    func svgaPlayerDidFinishedAnimation(_ player: SVGAPlayer) {
        print("动画播放完成")
    }
    
    func svgaPlayer(_ player: SVGAPlayer, didAnimatedToFrame frame: Int) {
        print("播放到第 \(frame) 帧")
    }
    
    func svgaPlayer(_ player: SVGAPlayer, didAnimatedToPercentage percentage: CGFloat) {
        print("播放进度: \(percentage * 100)%")
    }
}
```

## 主要类和方法

### SVGAPlayer

主要的播放器类，继承自 UIView。

**属性：**
- `delegate`: 代理对象
- `videoItem`: 视频实体
- `loops`: 循环次数
- `clearsAfterStop`: 停止后是否清除
- `fillMode`: 填充模式
- `mainRunLoopMode`: 主运行循环模式

**方法：**
- `startAnimation()`: 开始动画
- `startAnimationWithRange(_:reverse:)`: 在指定范围内播放
- `pauseAnimation()`: 暂停动画
- `stopAnimation()`: 停止动画
- `clear()`: 清除内容
- `stepToFrame(_:andPlay:)`: 跳转到指定帧
- `stepToPercentage(_:andPlay:)`: 跳转到指定百分比

### SVGAParser

解析器类，用于解析 SVGA 文件。

**属性：**
- `enabledMemoryCache`: 是否启用内存缓存

**方法：**
- `parseWithURL(_:completionBlock:failureBlock:)`: 从 URL 解析
- `parseWithURLRequest(_:completionBlock:failureBlock:)`: 从 URLRequest 解析
- `parseWithData(_:cacheKey:completionBlock:failureBlock:)`: 从 Data 解析
- `parseWithNamed(_:inBundle:completionBlock:failureBlock:)`: 从 Bundle 解析

### SVGAImageView

图像视图类，继承自 SVGAPlayer。

**属性：**
- `autoPlay`: 是否自动播放
- `imageName`: 动画名称

### SVGAVideoEntity

视频实体类，包含动画的所有信息。

**属性：**
- `videoSize`: 视频尺寸
- `FPS`: 帧率
- `frames`: 总帧数
- `images`: 图片字典
- `audiosData`: 音频数据字典
- `sprites`: 精灵数组
- `audios`: 音频数组

### SVGAExporter

导出器类，用于导出动画帧。

**方法：**
- `toImages()`: 导出为图片数组
- `saveImages(_:filePrefix:)`: 保存图片到指定路径

## 从 CocoaPods 迁移

如果您之前使用 CocoaPods 安装 SVGAPlayer，迁移到 Swift Package Manager 非常简单：

1. 移除 Podfile 中的 SVGAPlayer 依赖
2. 删除 Podfile.lock 和 Pods 目录
3. 运行 `pod deintegrate`（如果安装了）
4. 按照上述安装步骤添加 Swift Package 依赖

代码无需修改，API 完全兼容。

## 注意事项

- 最低支持 iOS 12.0
- 需要网络权限来加载远程 SVGA 文件
- 建议在真机上测试性能
- 大文件建议启用缓存机制

## 许可证

Apache-2.0 License

## 相关链接

- [原项目地址](https://github.com/svga/SVGAPlayer-iOS)
- [SVGA 官网](http://svga.io/)
- [SVGA 示例](https://github.com/yyued/SVGA-Samples)