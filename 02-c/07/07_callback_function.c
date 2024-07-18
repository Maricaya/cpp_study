#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 可以打印任意类型调数组
void printAllArray(void *pArray, int eleSize, int len, void (*myPrint)(void *)) {
  char *p = pArray;
  for (int i = 0; i < len; i++) {
    char *eleAddr = p + eleSize * i;
    myPrint(eleAddr);
  }
}

void printInt(void *data) {
  int *num = data;
  printf("%d\n", *num);
}

void test01() {
  int arr[5] = {1, 2, 3, 4, 5};
  int len = sizeof(arr) / sizeof(int);
  printAllArray(arr, sizeof(int), len, printInt);
}

void printChar(void *data) {
  char *c = data;
  printf("%c\n", *c);
}

void test02() {
  char arr[5] = {'h', 'o', 'o', 'w', 'd'};
  int len = sizeof(arr) / sizeof(char);
  printAllArray(arr, sizeof(char), len, printChar);
}

struct Person {
    char name[64];
    int age;
};

void printPersonArray(void *data) {
  struct Person *p = data;
  printf("name: %s, age: %d\n", p->name, p->age);
}

// 查找数组中的元素是否存在
int findArrayEle(
        void *pArray,
        int eleSize,
        int len,
        void *data,
        int (*myCompare)(void *, void *)
) {
  char *p = pArray;

  for (int i = 0; i < len; i++) {
    // 每个元素的首地址
    char *eleAddr = p + eleSize * i;

    if (myCompare(eleAddr, data)) {
      return 1;
    }
  }
  return 0;
}

int comparePerson(void *data1, void *data2) {
  struct Person *p1 = data1;
  struct Person *p2 = data2;

  return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test03() {
  struct Person personArray[] = {
          {"a", 1},
          {"a", 2},
          {"a", 3},
          {"a", 4},
          {"a", 5},
  };
  int len = sizeof(personArray) / sizeof(struct Person);
  printAllArray(
          personArray,
          sizeof(struct Person),
          len,
          printPersonArray
          );

  // 查找数组中指定的元素是否存在
  struct Person p = {"a", 5};
  int result = findArrayEle(
          personArray,
          sizeof(struct Person),
          len,
          &p,
          comparePerson
          );

  printInt(&result);
}

int main() {
//  test01();
//  test02();
  test03();
  return EXIT_SUCCESS;
}