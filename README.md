# OCBanoryPod

[![CI Status](https://img.shields.io/travis/“wangduo”/OCBanoryPod.svg?style=flat)](https://travis-ci.org/“wangduo”/OCBanoryPod)
[![Version](https://img.shields.io/cocoapods/v/OCBanoryPod.svg?style=flat)](https://cocoapods.org/pods/OCBanoryPod)
[![License](https://img.shields.io/cocoapods/l/OCBanoryPod.svg?style=flat)](https://cocoapods.org/pods/OCBanoryPod)
[![Platform](https://img.shields.io/cocoapods/p/OCBanoryPod.svg?style=flat)](https://cocoapods.org/pods/OCBanoryPod)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

OCBanoryPod is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'OCBanoryPod'
```

## Author

“wangduo”, cokeduo@163.com

## License

OCBanoryPod is available under the MIT license. See the LICENSE file for more info.


## 源码/二进制依赖配置
```
if ENV['IS_SOURCE'] || ENV['OCBanoryPod']
s.source_files = 'OCBanoryPod/Classes/**/*'
else
s.vendored_frameworks = 'OCBanoryPod/FrameWorks/**/OCBinaryFrameWork.framework'
end
```
## 源码依赖方式
```
IS_SOURCE=1 pod install     -> 所有组件都会源码依赖
OCBanoryPod=1 pod install   -> 可以指定特定组件依赖源码

执行如果没有效果，尝试清除pod缓存，pod cache clean --all
```
## 二进制依赖
```
pod install （默认）
```

## other

```
更改framework编译后存在的路径，默认在DriverData路径下，更改路径可以方便podspece文件里对framework路径的指定；
eg:  OCBanoryPod/FrameWorks/**/OCBinaryFrameWork.framework, 以后每次编译成功的framework文件都会存在与该路径下；

更改路径： Xcode - File - Workspace settings - Advanced - Custom - Relative to Workspace - Products 更改为自定义路径（Products当前目录为workspace当前目录）；
自定义路径： ../OCBanoryPod/FrameWorks
```

## 合并多架构framework

添加脚本，每次编译后自动获取debug,release下各架构framework，根据需要合并成所支持多架构的framework；
tips: 最终合并的framework存放到podspecs中所指定依赖的framework的目录，不用再做framework移动；

```

# Type a script or drag a script file from your workspace to insert its path.
TARGET_FRAMEWORK_NAME=${TARGET_NAME}
PROJECT_NAME=${PROJECT_NAME}

INSTALL_FRAMEWORK="../${PROJECT_NAME}/FrameWorks/${TARGET_FRAMEWORK_NAME}.framework"

# 编译结果目录
WRK_DIR=build

DEBUG_DEVICE_DIR="${WRK_DIR}/Debug-iphoneos/${TARGET_FRAMEWORK_NAME}.framework/${TARGET_FRAMEWORK_NAME}"
DEBUG_SIMULATOR_DIR="${WRK_DIR}/Debug-iphonesimulator/${TARGET_FRAMEWORK_NAME}.framework/${TARGET_FRAMEWORK_NAME}"

# release 模式架构支持 Debug -> Release
xcodebuild -configuration "Debug" -target "${TARGET_FRAMEWORK_NAME}" -sdk iphoneos clean build
xcodebuild -configuration "Debug" -target "${TARGET_FRAMEWORK_NAME}" -sdk iphonesimulator clean build


# 如果目录下最终的二进制文件已经存在则先做删除
if [ -d "${INSTALL_FRAMEWORK}" ]
then
rm -rf "${INSTALL_FRAMEWORK}"
fi

# 合并多架构framework到最终目录
lipo -create "${DEBUG_DEVICE_DIR}" "${DEBUG_SIMULATOR_DIR}" -output "${INSTALL_FRAMEWORK}"
```
