//
//  JJTool.h
//  OCBanoryPod
//
//  Created by 王铎 on 2019/12/18.
//

#import <Foundation/Foundation.h>


@interface JJTool : NSObject

+ (void)log;

// 添加log2方法，升级测试
+ (void)log2;
    
// 添加编译脚本，自动合成多架构支持framework,且移动到podspec指定framework目录
// 添加log3方法，升级测试
+ (void)log3;


@end
