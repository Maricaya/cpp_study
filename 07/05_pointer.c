#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(int a, char c) {
  printf("hello\n");
}

void test01() {
  // 1. 先定义出函数的类型，再通过类型定义函数指针
  typedef void (FUNC_TYPE)(int, char);

  FUNC_TYPE * pFunc = func;
  pFunc(10, 'a');

  // 2. 定义出函数指针的类型，通过类型来定义函数指针变量
  typedef void (* FUNC_TYPE2)(int, char);

  FUNC_TYPE2 pFunc2 = func;
  pFunc2(20, 'b');

  // 3. 直接定义函数指针变量
  // void (*)(int,char)
  void (*pFunc3)(int,char)  = func;
  pFunc3(30, 'c');

  // todo 为什么要有这些

  // 函数指针 和 指针函数 的区别
  // 函数指针：指向了函数的指针
  // 指针函数：函数返回值是指针的函数

}

// 函数指针的数组
void func1() {
  printf("func1 调用了\n");
}
void func2() {
  printf("func2 调用了\n");
}

void test02() {
  void (*pArray[3])();

  pArray[0] =func1;
  pArray[1] =func2;
  pArray[2] =func2;

  for (int i = 0; i < 2; i++) {
    pArray[i]();
  }

}

int main() {
//  test01();
  test02();
  return EXIT_SUCCESS;
}