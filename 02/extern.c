#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "heap.c"
// static 静态变量
//  特点：在运行前分配内存，程序运行结束，生命周期结束。   在本文件内都可以使用静态变量
// 全局作用域 a

static int a = 10;

void test011() {
  // 局部作用域 b
  static int b = 20;
}


void test021() {
  // 告诉编译器，下面代码中出现 g_a 不要报错，
  // 是外部链接属性，在其他文件中
  // extern 可以提高变量的作用域
  extern int g_a;

  printf("%d\n", g_a);
}

int main() {
  test021();
  return EXIT_SUCCESS;
}