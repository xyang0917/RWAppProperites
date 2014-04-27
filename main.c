//
//  main.c
//  读写配置文件
//
//  Created by 杨信 on 14-4-24.
//  Copyright (c) 2014年 yangxin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Properties.h"

int main(int argc, const char * argv[])
{
    int ret;
    void *handle;
    const char *filepath = "/Users/yangxin/Desktop/props.txt";
    // 初始化
    ret = init(filepath, &handle);
    if (ret != 0) {
        printf("env init error:%d\n",ret);
        return 0;
    }
    
    char valuebuf[128];
    // 测试获取配置项
    ret = getValue(handle, "host", valuebuf);
    if (ret == 0) {
        printf("value=%s\n",valuebuf);
    }
    else {
        printf("获取值host的值失败\n");
    }
    
    // 测试修改配置项
    ret = setValue(handle, "version", "1.2.3");
    if (ret == 0) {
        printf("修改成功!\n");
    }
    else{
        printf("修改失败\n");
    }
    
    // 测试添加配置项
    ret = add(handle, "pool_connection_countxx", "2000");
    if (ret == 0) {
        printf("添加成功!\n");
    }
    else{
        printf("添加失败\n");
    }
    
    // 测试删除配置项
    ret = del(handle, "connectionMax");
    if (ret == 0) {
        printf("删除成功!\n");
    }
    else{
        printf("删除失败\n");
    }
    
    // 测试获取所有配置项的key
    char **keys = NULL;
    int keyscount;
    ret = getKeys(handle, &keys, &keyscount);
    if (ret == 0) {
        printf("一共有%d个Key\n",keyscount);
        for (int i =0; i<keyscount; i++) {
            printf("%s\n",keys[i]);
        }
    }
    // 释放内存
    ret = free_keys(&keys, &keyscount);
    if (ret == 0) {
        printf("keys释放内存成功!\n");
    }
    
    // 测试获取所有配置项的value
    char **values = NULL;
    int valuescount;
    ret = getValues(handle, &values, &valuescount);
    if (ret == 0) {
        printf("一共有%d个Value\n",valuescount);
        for (int i = 0; i < valuescount; i++) {
            printf("%s",values[i]);
        }
    }
    // 释放内存
    ret = free_values(&values, &valuescount);
    if (ret == 0) {
        printf("values释放内存成功!\n");
    }
    
    // 释放资源
    ret = release(&handle);
    if (ret != 0) {
        printf("env release error:%d\n",ret);
    }
    
    return 0;
}

