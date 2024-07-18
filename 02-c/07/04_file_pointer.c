#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <QDebug>

void func(int a) {
  printf("hello world\n");
//  qDebug("hello world");
}

void test01() {
  func(1);
  int *p = func;
  printf("%d\n", func);
  // 利用函数指针，指向函数地址
  void(*pFunc)(int ) = (void(*)(int ))p;

  pFunc(1);
}

int main() {
  test01();
  return EXIT_SUCCESS;
}