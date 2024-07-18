#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
  // 从小到大的排序
  int arr[] = {2, 5, 1, 3, 4};

  int len = 5;
  for (int i = 0; i < len; i++) {
    int min = arr[i];
    int min_pointer = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < min) {
        min = arr[j];
        min_pointer = j;
      }
    }
    arr[min_pointer] = arr[i];
    arr[i] = min;
  }

  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }
}

void mySort(int arr[], int len) {

}

void test01_2() {
  // 从小到大的排序
  int arr[] = {2, 5, 1, 3, 4};
  int len = sizeof(arr) / sizeof(int);
  mySort(arr, len);
}

void test02() {
  // 对指针数组进行排序  选择排序
  char *pArray[] = {"aaa", "fff", "bbb", "ccc", "eee"};
  int len = sizeof(pArray) / sizeof(char *);

  for (int i = 0; i < len; i++) {
    int max = i;
    for (int j = i + 1; j < len; j++) {
      if (strcmp(pArray[max], pArray[j]) < 0) {
        max = j;
      }
    }
    if (max != i) { // only swap if necessary
      char *temp = pArray[i];
      pArray[i] = pArray[max];
      pArray[max] = temp;
    }
  }
  for (int i = 0; i < len; i++) {
    printf("%s\n", pArray[i]);
  }
}

int main() {
  test02();
  return EXIT_SUCCESS;
}