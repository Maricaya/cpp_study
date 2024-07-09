#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 数组指针的定义方式
// 1. 先定义数组类型，再通过类型定义数组
//
void test01() {
  int arr[5] = {1, 2, 3, 4, 5};

  typedef int(ARRAY_TYPE)[5]; // ARRAY_TYPE 代表存放 5 个 int 类型元素的数组 的数组类型

  ARRAY_TYPE arr2;

  for (int i = 0; i < 5; i++) {
    arr2[i] = 100 + i;
  }
  for (int i = 0; i < 5; i++) {
    printf("%d\n", arr2[i]);
  }

  ARRAY_TYPE *arrP = &arr2;
  // *arrP == arr == 数组名
  for (int i = 0; i < 5; i++) {
    printf("%d\n", (*arrP)[i]);
    printf("%d\n", (arr2)[i]);
  }
}

void test02() {
  // 先定义数组指针的类型，再通过类型定义数组指针
  int arr[5] = {1, 2, 3, 4, 5};

  typedef int(*ARRAY_TYPE)[5];

  ARRAY_TYPE arrP = &arr;

  for (int i = 0; i < 5; i++) {
    printf("%d\n", (*arrP)[i]);
  }
}

void test03() {
  // 直接定义数组指针
  int arr[5] = {1, 2, 3, 4, 5};

  //int *p = (int *) &arr;
  int (* p)[5] = &arr;

  for (int i = 0; i < 5; i++) {
    printf("%d\n", (*p)[i]);
  }
}

int main() {
  test03();
  return EXIT_SUCCESS;
}