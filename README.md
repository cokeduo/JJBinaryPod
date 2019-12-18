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

“wangduo”, wangduo@akulaku.com

## License

OCBanoryPod is available under the MIT license. See the LICENSE file for more info.


## 源码/二进制依赖配置eerdc
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

## 建议（采坑）

OCBinaryFrameWork.framework 的名字建议pod组件名名称，不要随意命名，否则使用过程中源码和二进制切换头文件导入方式也需要更改；
