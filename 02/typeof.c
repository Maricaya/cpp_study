//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. typedef 使用
// 可以起别名
struct Person {
    char name[64];
    int age;
};

typedef struct Person myPerson;


typedef struct Person2 {
    char name[64];
    int age;
}myPerson2;

void test01() {
  struct Person p = {"aaa", 10};

  myPerson p2 = {"bbb", 20};
}

//2、区分数据类型
void test02() {
  typedef char *PCHAR;
  PCHAR p1, p2;
//  char *p1, p2;

  char *p3, *p4;
}

// 3、提高移植性
typedef long long MYINT;
void test03() {
  MYINT a = 10;
  MYINT b = 10;

}

int main() {
  char buf[1024];
  strcpy(buf, "hello world");
  printf("%s\n", buf);

  printf("hello");


  return EXIT_SUCCESS;
}