// swift-tools-version: 5.7
import PackageDescription

let package = Package(
    name: "SVGAPlayer",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "SVGAPlayer",
            targets: ["SVGAPlayer"]
        ),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "SVGAPlayer",
            dependencies: ["Protobuf", "SSZipArchive"],
            path: "Sources/SVGAPlayer",
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("include"),
                .headerSearchPath("../Protobuf/objectivec"),
                .headerSearchPath("../SSZipArchive"),
                .define("GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS", to: "0"),
                .define("TARGET_OS_IPHONE", to: "1")
            ],
            cxxSettings: [
                .define("GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS", to: "0")
            ],
            swiftSettings: [
                .define("SWIFT_PACKAGE")
            ],
            linkerSettings: [
                .linkedFramework("Foundation"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("QuartzCore"),
                .linkedFramework("AVFoundation"),
                .linkedFramework("UIKit")
            ]
        ),
        .target(
            name: "Protobuf",
            path: "Sources/Protobuf",
            publicHeadersPath: "objectivec",
            cSettings: [
                .headerSearchPath("objectivec"),
                .define("GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS", to: "0"),
                .unsafeFlags(["-fno-objc-arc"])
            ]
        ),
        .target(
            name: "SSZipArchive",
            path: "Sources/SSZipArchive",
            publicHeadersPath: ".",
            cSettings: [
                .headerSearchPath("."),
                .define("HAVE_INTTYPES_H"),
                .define("HAVE_PKCRYPT"),
                .define("HAVE_STDINT_H"),
                .define("HAVE_WZAES"),
                .define("HAVE_ZLIB"),
                .unsafeFlags(["-fno-objc-arc"])
            ]
        ),
        .testTarget(
            name: "SVGAPlayerTests",
            dependencies: ["SVGAPlayer"],
            path: "Tests/SVGAPlayerTests"
        )
    ]
)
