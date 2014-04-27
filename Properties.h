//
//  Properties.h
//  读写配置文件
//
//  Created by 杨信 on 14-4-24.
//  Copyright (c) 2014年 yangxin. All rights reserved.
//

#ifndef _______Properties_h
#define _______Properties_h

#ifdef _cplusplus
extern "C" {
#endif
    
    // 初始化环境，成功返回0，失败返回非0值
    int init(const char *filepath,void **handle);
    
    // 根据KEY获取值，找到返回0，如果未找到返回非0值
    int getValue(void *handle, const char *key, char *value);
    
    // 修改key对应的属性值，修改成功返回0，失败返回非0值
    int setValue(void *handle, const char *key, const char *value);
    
    // 添加一个属性，添加成功返回0，失败返回非0值
    int add(void *handle, const char *key, const char *value);
    
    // 删除一个属性，删除成功返回0，失败返回非0值
    int del(void *handle, const char *key);
    
    // 获取属性文件中所有的key，获取成功返回0，失败返回非0值
    int getKeys(void *handle, char ***keys, int *keyscount);
    
    // 释放所有key的内存空间，成功返回0，失败返回非0值
    int free_keys(char ***keys,int *keyscount);
    
    // 获取属性文件中所有的值，成功返回0，失败返回非0值
    int getValues(void *handle, char ***values, int *valuescount);
    
    // 释放所有value的内存空间，成功返回0，失败返回非0值
    int free_values(char ***values, int *valuescount);
    
    // 获取属性数量，成功返回0，失败返回非0值
    int getCount(void *handle, int *count);
    
    // 释放环境资源，成功返回0，失败返回非0值
    int release(void **handle);
    
    
#ifdef _cplusplus
}
#endif

#endif
