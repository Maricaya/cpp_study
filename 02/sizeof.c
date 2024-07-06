#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. sizeof 本质,是不是函数？不是，而是操作符
void test01() {
  double d = 3.14;
  printf("%d %d \n", sizeof d, sizeof(int));
}

// 2. sizeof符号类型，无符号整数
void test02() {
  unsigned int a = 10;
  // 当 unsigned int 和 int 做运算，会统一 unsigned
  if (a - 20 > 0) {
    printf(">0\n");
  } else {
    printf("<0\n");
  }

  if (sizeof(int) - 5 > 0) {
    printf(">0\n");
  } else {
    printf("<0\n");
  }
}

// sizeof 用途，统计数组长度，
// 当数组名做函数参数，会退化为指针，指向数据中第一个元素当位置
// 所以不能封装
void calculateArray(arr[]) {
  printf("array length = %lu\n", sizeof(arr));
}

void test03() {
  int arr[] = {1,2,3,4,5,6,7,8};
  calculateArray(arr);
  printf("array length = %d\n", sizeof(arr));
}

int main() {
  test02();
  return EXIT_SUCCESS;
}