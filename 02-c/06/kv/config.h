#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 配置信息结构体
struct ConfigInfo {
    char key[64];
    char value[64];
};

// 获取有效行数
int getFileLines(char *filePath);

// 检测当前行是否是有效信息
int isValidLines(char *str);

// 解析文件
void parseFile(char *filePath, int lines, struct ConfigInfo **configInfo);

// 根据 key 获取对应value
char * getInfoByKey(char *key, struct ConfigInfo * configInfo, int len);

// 释放内存
void freeConfigInfo(struct ConfigInfo * configInfo);