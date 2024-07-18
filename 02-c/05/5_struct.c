#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct Person {
//    char name[64];
//    int age;
//} ;
//
//typedef struct Person myPerson;

typedef struct Person {
    char name[64];
    int age;
} myPerson;

void test01() {
  struct Person p = {"Tom", 18};
  myPerson e2 = {"Jerry", 20};
}

struct Person2 {
    char name[64];
    int age;
} myPerson2 = {"aaa", 20};

void test02() {
  printf("name: %s, age: %d\n", myPerson2.name, myPerson2.age);
}

// 匿名结构体
struct {
    char name[64];
    int age;
} myPerson3 = {"bbb", 30};

void printArray(struct Person pPerson[4], int len);

void test03() {
  printf("name: %s, age: %d\n", myPerson3.name, myPerson3.age);
}

// 结构体创建
void test04() {
  // 创建在栈上
  struct Person p = {"bbb", 30};
  printf("name: %s, age: %d\n", p.name, p.age);
  // 创建在堆区
  struct Person *p2 = malloc(sizeof(struct Person));
  strcpy(p2->name, "cccc");
  p2->age = 20;
  printf("name: %s, age: %d\n", p2->name, p2->age);

  if (p2 != NULL) {
    free(p2);
    p2 = NULL;
  }
}

// 结构体变量数组创建
void test05() {
  // 在栈上分配内存
  struct Person persons[] = {
          {"aaa", 10},
          {"bbb", 20},
          {"ccc", 30},
          {"ddd", 40},
  };
  int len = sizeof (persons) / sizeof (struct  Person);
  printArray(persons, len);

  // 在堆区分配
  struct Person *pArray = malloc(sizeof (struct Person) * len);
  for (int i = 0; i < len; i++) {
    sprintf(pArray[i].name, "name_%d", i+1);
    pArray[i].age = 18+i;
//    printf("name: %s, age: %d\n", pArray[i].name, pArray[i].age);
  }
  printArray(pArray, len);

  if (pArray != NULL) {
    free(pArray);
    pArray = NULL;
  }
}

void printArray(struct Person pPerson[], int len) {
  for (int i = 0; i < len; i++) {
    printf("name: %s, age: %d\n", pPerson[i].name, pPerson[i].age);
  }
}

int main() {
  test01();
  test02();
  test03();
  test04();
  test05();
  return EXIT_SUCCESS;
}