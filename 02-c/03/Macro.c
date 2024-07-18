#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MY_ADD(x,y) (x+y)

// 1. 宏函数需要加小括号修饰，保证运算的完整性
// 2. 通常会将频繁、短小的函数，写成宏函数
// 3. 宏函数会比普通函数在一定程度上效率高，省去普通函数入栈、出栈时间上的开销
// 以空间换时间
void test01() {
  int a = MY_ADD(1, 2) * 20;
  printf("%d\n", a);
}

int main () {
  test01();
  return EXIT_SUCCESS;
}