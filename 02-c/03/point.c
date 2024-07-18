#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. 不能向 NULL 或者非法内存拷贝数据
void test01() {
  char *p = NULL;
  strcpy(p, "1111"); //error

  char * q = 0x1122;
  // 给q指向内存区域拷贝内容
  strcpy(q, "222"); // error
}

// 指针操作超越变量作用域
int * doWork() {
  int a = 10;
  int *p = &a;
  return p;
}
// 2.野指针出现的情况
void test02 () {
  // 指针变量未初始化
  //int * p;
  //printf("%d\n", *p);

  //指针释放后未置空
  char * str = malloc(100);
  free(str);
  // 记住释放后置空，防止野指针出现
  str = NULL;
  free(str);
  // 空指针可以重复释放，但是野指针不可以

  int * p = doWork();
  printf("%d\n", *p);
  printf("%d\n", *p);
}


int main() {
  test02();
  return EXIT_SUCCESS;
}