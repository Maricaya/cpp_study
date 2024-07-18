#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void * func() {
  char * p = malloc(10); // 堆区数据，只要没有释放，都可以使用
  return p;
}

void test01() {
  int b = 10;
  func();
  printf("%d\n", 1);
}

int main () {
  int a = 10;
  test01();
  return EXIT_SUCCESS;
}