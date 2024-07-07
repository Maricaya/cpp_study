#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

// 1. 指针的步长，代表，指针+1之后跳跃的字节数
void test01() {
  char *p = NULL;
  printf("%d\n", p);
  printf("%d\n", p + 1);

  double *p2= NULL;
  printf("%d\n", p2);
  printf("%d\n", p2+1);
}
// 2. 解引用的时候，解出的字节数量
void test02 () {
  char buf[1024] = {0};

  int a = 1000;

  memcpy(buf+1, &a, sizeof (int));

  char * p = buf;
  printf("%d\n", *(int *) (p+1));
}

// 步长练习，自定义数据类型练习
struct Person
{
    char a; // 0~3
    int b; // 4~7
    char buf[64]; // 8~71
    int d; // 72~75
};

void test03() {
  struct Person p = {'a', 10, "hello world", 20};

  printf("d的偏移量%lu\n", offsetof(struct Person, d));


  char * pp = &p;
  printf("%d\n", *(int *) (pp+72));
}


int main() {
  test03();
  return EXIT_SUCCESS;
}