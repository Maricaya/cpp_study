#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 回调函数

// 可以打印任意类型的数据
void printText(void * data, void (*myPrint) (void *)) {
  myPrint(data);
}

void myPrintInt(void * data) {
  int * num = data;
  printf("%d\n", *num);
}

void test01() {
  int a = 10;
  printText(&a, myPrintInt);
}

struct Person {
    char name[64];
    int age;
};

void myPrintPerson(void * data) {
  struct Person * p = data;
  printf("name: %s, age: %d\n", p->name,p->age);
}

void test02() {
  struct Person p = {"Tom", 18};
  printText(&p, myPrintPerson);
}

int main() {
//  test01();
  test02();
  return EXIT_SUCCESS;
}