#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. %*s 或者 %*d 跳过数据
void test01() {
  char *str = "12345abcde";

  char buf[1024] = {0};

  sscanf(str, "%*d%s", buf);

  printf("--- %s ---\n", buf);
}

void test02() {
  char *str = "abcde12345 "; // 忽略遇到了空格，或者\t，代表忽略结束

  char buf[1024] = {0};
  sscanf(str, "%*[a-z]%s", buf);
  //sscanf(str, "%s%s", buf);

  printf("--- %s ---\n", buf);
}

// %[width]s 读指定宽度读数据
void test03() {
  char *str = "12345abcde";

  char buf[1024] = {0};
  sscanf(str, "%6s", buf);

  printf("--- %s ---\n", buf);
}

void test04() {
  char *str = "123abcd$myname@000qwe";

  char buf[1024] = {0};

  sscanf(str, "%*[^$]$%[^@]", buf);

  printf("--- %s ---\n", buf);
}

void test05() {
  char *str = "hello@it.cn";

  char buf[1024] = {0};
  char buf1[1024] = {0};

  sscanf(str, "%[a-z]%*[@]%s", buf, buf1);
//  sscanf(str, "%[a-z]@%s", buf, buf1);

  printf("--- %s -- %s---\n", buf, buf1);
}

void test06() {
  char *str = "1.2.3.4";

  int a;
  int b;
  int c;
  int d;

  sscanf(str, "%d.%d.%d.%d", &a,&b,&c,&d );

  printf("--- %d %d %d %d---\n", a, b,c,d);
}

int main() {
  test05();
  test06();
  return EXIT_SUCCESS;
}