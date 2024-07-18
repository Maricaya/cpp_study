#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 注意事项：不要返回局部变量的地址
// 局部变量在函数执行之后就被释放了，释放的内存就没有权限操作了，如果操作，结果未知。
int * myFunc() {
  int a = 10;
  return &a;
}

void test01() {
  // 局部变量a早已被释放，因此我们没有权限操作这块内存
  int * p = myFunc();
  int *b = p;
  printf("*p = %d\n", *b);
  printf("*p = %d\n", *b);
  printf("*p = %d\n", *b);

  printf("*p = %d\n", *p);
}

char * getString()
{
  char str[] = "hello world";
  return str;
}

void test02() {
  char * p = NULL;
  p = getString();
  printf("%s\n", p);
}

int main() {
  test02();
  return EXIT_SUCCESS;
}