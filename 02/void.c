#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. void 无类型，不可以通过 void 创建变量，原因无法给 void 无类型变量分配内存

// 2. 限定函数返回值，限定函数参数
// 3. void * 万能指针，不管任意类型的指针都是4个字节
void test03() {
  void * p = NULL;
  int * pInt = NULL;
  char * pChar = NULL;

  pChar = (char *) pInt;
  pChar = p; // 万能指针，不用强制类型转换
}



int main () {
  test03();
  return EXIT_SUCCESS;
}