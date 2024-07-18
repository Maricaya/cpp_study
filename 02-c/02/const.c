#include <stdio.h>

#define PI 3.14

// const 修饰的变量
// 全局变量
const int a = 10; // 常量区. 间接修改，语法通过，运行失败，原因：受到常量区的保护

void test01() {
  int * p = &a;
  *p = 100;
  printf("%d\n", a);
}

void test02() {
  const int b = 10;
  printf("%d\n", b);
  int *p = &b;
  *p = 20;
  printf("%d\n", b);
}

// 2. 字符串常量
void test03() {
  char * p1 = "hello world";
  char * p2 = "hello world";
  char * p3 = "hello world";

  printf("%s\n", p1);
  printf("%d\n", p2);
  printf("%d\n", p3);
}

// 尽量不要修改字符串常量
void test04() {
  char * str = "hello world";
//  str[0] = 'x';
  printf("---%s\n", str);

}

int main(void) {
  test02();
  test03();
  test04();

  return 0;
}
