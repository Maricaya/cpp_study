#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 预处理
// 宏定义

// 宏常量
  // 不重视作用域
  // 可以利用 undef 卸载宏
  // 宏常量 没有数据类型

void test01() {
  #define MAX 1024

}

// 条件编译
//#define DEBUG

#ifdef DEBUG
void func() {
  printf("debug版本\n");
}
#else
void func() {
  printf("release版本\n");
}
#endif

int main() {
  printf("MAX = %d\n", MAX);
  printf("FILE = %s\n", __FILE__);
  printf("FILE = %d\n", __LINE__);
  printf("FILE = %s\n", __DATE__);
  printf("FILE = %s\n", __TIME__);
  func();
  return EXIT_SUCCESS;
}