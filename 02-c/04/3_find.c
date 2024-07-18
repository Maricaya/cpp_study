#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
  char *str = "abcdefgdnfabcde";
  char *target = "dnf";

  int i = 0; //
  int j = 0;

  while (target[j] != '\0') {
    if (str[i] == target[j]) {
      j++;
    }
    i++;
  }

  printf("%s - %s\n", str, target);
  printf("start: %lu; end: %d \n", i - strlen(target), i);
}

int myStr(char *str, char *subStr) {
  int num = 0;
  while (*str != '\0') {
    if (*str != *subStr) {
      num++;
      str++;
      continue;
    }
    printf("%s, %s, %lu \n", str, subStr, strlen(subStr));

    printf("%d\n", memcmp(str, subStr, strlen(subStr)));

    if (memcmp(str, subStr, strlen(subStr)) == 0) {
      num++;
      return num;
    }
    str++;


//    char *tempStr = str;
//    char *tempSubstr = subStr;
//    while (*tempSubstr != '\0') {
//      if (*tempStr != *tempSubstr) {
//        // 匹配失败
//        str++;
//        num++;
//        break;
//      }
//      tempStr++;
//      tempSubstr++;
//    };
//
//    if (*tempSubstr == '\0') {
//      return num;
//    }
  }
  return -1;
}

int myStr2(char *str, char *target) {
  int num = 0;
  while (*str != '\0') {
    if (*str == *target) {
      char *temp = str;
      char *tempTarget = target;
      while (*tempTarget != '\0') {
        if (*temp == *tempTarget) {
          temp++;
          tempTarget++;
        } else {
          break;
        }
      }
      if (*tempTarget == '\0') {
        return num;
      }
    }
    str++;
    num++;
  }
  printf("str: %s", str);
  return -1;
}

void test02() {
  char *str = "abcdefgdnfabcde";
  int ret = myStr2(str, "dnf");

  if (ret != -1) {
    printf("positionis %d\n", ret);
  }
}

int main() {
  test02();

  return EXIT_SUCCESS;
}