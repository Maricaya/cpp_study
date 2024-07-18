#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"


int main() {
  char *filePath = "./kv/config.txt";
  int lines = getFileLines(filePath);
  printf("lines: %d \n", lines);

  struct ConfigInfo *configInfo = NULL;
  parseFile(filePath, lines, &configInfo);

  // 测试 根据 key 获取 value
  printf("heroId = %s\n", getInfoByKey("heroId", configInfo, lines));
  printf("heroName = %s\n", getInfoByKey("heroName", configInfo, lines));
  printf("heroAtk = %s\n", getInfoByKey("heroAtk", configInfo, lines));
  printf("heroDef = %s\n", getInfoByKey("heroDef", configInfo, lines));
  printf("heroInfo = %s\n", getInfoByKey("heroInfo", configInfo, lines));

  // 释放空间
  freeConfigInfo(configInfo);
  configInfo = NULL;


  return EXIT_SUCCESS;
}