#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 输入特性：在主调函数中分配内存，被调函数中使用
void func(char *p) {
  strcpy(p, "hello world");
}

void test01() {
  // 在 test01中分配了内存，分配在栈上
  char buf[1024] = {0};

  func(buf);

  printf("%s\n", buf);
}

void printString(char *str) {
  printf("%s\n", str + 6);
}

void test02() {
  char *p = malloc(sizeof(char) * 64);
  memset(p, 0, 64);
  strcpy(p, "hello world");
  printString(p);

  if (p != NULL) {
    free(p);
    p = NULL;
  }
}

// 输出特性，在被调函数中分配内存，主调函数使用
void allocateSpace(char **pp) {
  char *str = malloc(sizeof(char) * 64);
  memset(str, 0, 64);
  strcpy(str, "hello world");
  *pp = str;
}

void test03() {
  char *p = NULL;
  allocateSpace(&p);

  printf("%s\n", p);
}

int main() {
  test03();
  return EXIT_SUCCESS;
}