#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 变量的修改方式

void test01() {
// 1. 直接修改
  int a = 10;
  a = 20;
// 2. 间接修改
  int *p = &a;
  *p = 30;
  printf("a=%d\n", a);
}

struct Person {
    char a; // 0
    int b; // 4
    char c; // 8
    int d; // 12
};

void test02() {
  struct Person p = {'a', 10, 'b', 20};
  //直接修改属性
  // p.d = 1000;
  //间接修改
  struct Person *pp = &p;
  pp->d = 1000;
  printf("%d\n", p.d);
//  printf("%d\n", pp + 1);

// 底层
//  char *pp = &p;
//  *(int *)(pp + 12) = 2000;
//
//  printf("d 属性为：%d\n", p.d);
//  printf("d 属性为：%d\n", *(int*)(pp+12));
//  printf("d 属性为：%d\n", *(int*)((int*)pp+3));
}

int main() {
  test02();
  return EXIT_SUCCESS;
}