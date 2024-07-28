#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void insertion_sort(int arr[], int len) {
  int i, j, key;
  for (i = 1; i < len; i++) {
    key = arr[i];
    j = i - 1;
    while ((j >= 0) && (arr[j] > key)) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void test01() {
  int arr[] = {1, 3, 8, 4, 100, 0};
  insertion_sort(arr, sizeof arr/sizeof (int));
}

int main() {
  test01();
  return EXIT_SUCCESS;
}