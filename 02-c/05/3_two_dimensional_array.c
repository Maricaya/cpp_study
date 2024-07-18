#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
  int arr[3][3] = {
          {1, 2, 3},
          {4, 5, 6},
          {7, 8, 9}
  };
  //  int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //  int arr3[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // 除了两种特殊情况外，二维数组名称是 指向第一个一维数组 数组
  // 特殊情况1 sizeof
  // 特殊情况2 对数组名取地址 &arr 获取的是二维数组的 数组指针
  printf("%lu\n", sizeof(arr));

  int (*pArray)[3] = arr;
  printf("%d\n", (*pArray)[0]);

  int (*p)[3][3] = &arr;
  printf("%d\n", (*p)[0][0]);

  // 访问二维数组中 6
  printf("%d\n", arr[1][2]); // 给人看
  printf("%d\n", *(*(pArray + 1) + 2)); // 给机器看
}

void printArray(int (*arr)[3], int row, int col) {
//void printArray(int arr[][3], int row, int col) {
//void printArray(int arr[3][3], int row, int col) {
// arr[3][3] 相当于 一维数组指针 int(*arr)[3]
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      //      printf("%d ", arr[i][j]);
      printf("%d ", *(*(arr + i) + j));
    }
    printf("\n");
  }
}

// 二维数组做函数参数
void test02() {
  int arr[3][3] = {
          {1, 2, 3},
          {4, 5, 6},
          {7, 8, 9}
  };

  printArray(arr, 3, 3);
}

int main() {
  test02();
  return EXIT_SUCCESS;
}