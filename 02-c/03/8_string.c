#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
  // 最后应该加上 '\0'
  char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  printf("%s\n", str1);

  // 字符数组部分初始化，剩余填 0
  char str2[100] = {'h', 'e', 'l', 'l', 'o'};
  printf("%s\n", str2);

  char str3[] = "hello";
  printf("%s\n", str3);
  printf("sizeof str3: %lu\n", sizeof(str3));
  printf("strlen str3: %lu\n", strlen(str3));

  // 那么如果我这么写，结果是多少呢？
  char str4[100] = "hello";
  printf("sizeof str4: %lu\n", sizeof(str4));
  printf("strlen str4: %lu\n", strlen(str4));

  char str5[] = "hello\0world";
  printf("%s\n", str5);
  printf("sizeof str5: %lu\n", sizeof(str5));
  printf("strlen str5: %lu\n", strlen(str5));

  char str6[] = "hello\012world";
  printf("%s\n", str6);
  printf("sizeof str6: %lu\n", sizeof(str6));
  printf("strlen str6: %lu\n", strlen(str6));
}

// string copy
// 1. 利用 []
void copyString01(char *dest, char *src) {
  int len = strlen(src);
  for (int i = 0; i < len; i++) {
    dest[i] = src[i];
  }
  dest[len] = '\0';
}

// 2. 利用字符串指针
void copyString02(char *dest, char *src) {
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest='\0';
}

// 3.
void copyString03(char *dest, char *src) {
  while (*dest++ = *src++) {

  }
}

void test02() {
  char *str = "hello world";
  char buf[1024];
  copyString03(buf, str);
  printf("%s\n", buf);
}

// 字符串翻转
void reverseString01(char * str) {
  // 利用 []
  int len = strlen(str);
  int start = 0;
  int end = len - 1;
  while (start-end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    start++;
    end--;
  }
}
// 指针
void reverseString02( char * str) {
  int len = strlen(str);
  char * start = str;
  char * end = str + len -1;

  while (start < end) {
    char temp = * start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

void test03() {
  char str[] = "abcdefg";

  reverseString02(str);

  printf("%s\n", str);
}

void test() {
  char buf[1024] = {0};
  sprintf(buf, "hello %s\n", "John");
  printf("buf:%s\n", buf);
}

int main() {
  test();
  return EXIT_SUCCESS;
}