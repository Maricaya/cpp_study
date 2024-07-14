#include "config.h"

int getFileLines(char *filePath) {
  FILE *file = fopen(filePath, "r");

  if (file == NULL) {
    return -1;
  }

  char buf[1024] = {0};
  int lines = 0;
  while (fgets(buf, 1024, file) != NULL) {
    if (isValidLines(buf)) {
      lines++;
      memset(buf, 0, 1024);
    }
  }

  fclose(file);
  return lines;
}

int isValidLines(char *str) {
  if (strchr(str, ':') == NULL) {
    return 0; // 返回假 代表无效
  }
  return 1;
}

void parseFile(char *filePath, int lines, struct ConfigInfo **configInfo) {
  struct ConfigInfo *info = malloc(sizeof(struct ConfigInfo) * lines);

  if (info == NULL) {
    return;
  }

  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    return;
  }
  char buf[1024] = {0};
  int index = 0;
  while (fgets(buf, 1024, file) != NULL) {
    if (isValidLines(buf)) {
      // 有效信息 才去解析
      // 清空 key 和 value
      // herName:aaaa\n
      memset(info[index].key, 0, 64);
      memset(info[index].value, 0, 64);
      char *pos = strchr(buf, ':');
      strncpy(info[index].key, buf, pos - buf);
      strncpy(info[index].value, pos + 1, strlen(pos + 1) - 1);
      index++;
    }
    memset(buf, 0, 1024);
  }
  *configInfo = info;
}

char *getInfoByKey(char *key, struct ConfigInfo *configInfo, int len) {
  for (int i = 0; i < len; i++) {
    if (strcmp(key, configInfo[i].key) == 0) {
      return configInfo[i].value;
    }
  }
  return NULL;
}

void freeConfigInfo(struct ConfigInfo * configInfo) {
  if (configInfo!=NULL) {
    free(configInfo);
    configInfo = NULL;
  }
}