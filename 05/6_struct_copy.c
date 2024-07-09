#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[64];
    int age;
};

// 结构体深浅copy
void test01() {
  struct Person p1 = {"Tom", 18};
  struct Person p2 = {"Jerry", 20};

  printf("p1 name: %s, p1 age: %d \n", p1.name, p1.age);
  printf("p2 name: %s, p2 age: %d \n", p2.name, p2.age);
}

struct Person2 {
    char * name;
    int age;
};

void test02 () {
  struct Person2 p1 = {};
  p1.name = malloc(sizeof (char) * 64);
  strcpy(p1.name, "Tom");
  p1.age = 18;

  struct Person2 p2 = {};
  p2.name = malloc(sizeof (char) * 128);
  strcpy(p2.name, "Amy");
  p2.age = 20;

  // p1 = p2; // shallow copy 逐字节拷贝

  // 先释放原来的堆区
  if (p1.name != NULL) {
    free(p1.name);
    p1.name = NULL;
  }
  p1.name = malloc(strlen(p2.name) + 1); // + '\0'
  strcpy(p1.name, p2.name);
  p2.age = p1.age;


  printf("p1 name: %s, p1 age: %d \n", p1.name, p1.age);
  printf("p2 name: %s, p2 age: %d \n", p2.name, p2.age);

  if (p1.name != NULL) {
    free(p1.name);
    p1.name = NULL;
  }
  // 1. 堆区内容重复释放
  // 2. p1.name = Tom 没有释放， 内存泄漏
  // 解决方案，自己写 deep copy，而不是 使用 =
  if (p2.name != NULL) {
    free(p2.name);
    p2.name = NULL;
  }
}

int main() {
  test02();
  return EXIT_SUCCESS;
}