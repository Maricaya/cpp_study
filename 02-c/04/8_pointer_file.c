#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFileData(FILE *pFile, int len, char **pString);

void showFileData(char **pString, int len);

int getFileLines(FILE *pFile) {
  if (pFile == NULL) {
    return -1;
  }
  char buf[1024] = {0};
  int lines = 0;
  while (fgets(buf, 1024, pFile) != NULL) {
    lines++;
  }
  // 将文件光标置为首
  fseek(pFile, 0, SEEK_SET);
  return lines;
}

void test01() {
  // 打开文件
  FILE *pFile = fopen("./04/test.txt", "r");
  if (pFile == NULL) {
    printf("file open failed\n");
    return;
  }

  // 统计有效行数
  int len = getFileLines(pFile);
//  int len = 5;
  printf("%d\n", len);

  char **pArray = malloc(sizeof(char *) * len);

  // 读取文件中的数据，并且放入到 pArray 中
  readFileData(pFile, len, pArray);

  // 读取数据
  showFileData(pArray, len);

  // 释放堆区内容
  free(pArray);
  pArray = NULL;
  // 关闭文件
  fclose(pFile);
}

void showFileData(char **pArray, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d行的数据：%s", i + 1, pArray[i]);
  }
}

void readFileData(FILE *pFile, int len, char **pArray) {
  if (pFile == NULL || len <= 0 || pArray == NULL) {
    return;
  }

  char buf[1024] = {0};

  int index = 0;
  while (fgets(buf, 1024, pFile) != NULL) {
    /*
     * aaaaa
     * bbb
     * ccc
     * */
    int currentLen = strlen(buf) + 1;
    char *currentStrP = malloc(sizeof(char) * currentLen);
    strcpy(currentStrP, buf);
    pArray[index++] = currentStrP;
    memset(buf, 0, 1024);
  }

}

int main() {
  test01();
  return EXIT_SUCCESS;
}