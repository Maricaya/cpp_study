#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void allocateSpace(int **p, int len) {
  int *temp = malloc(sizeof(int) * len);
  for (int i = 0; i < len; i++) {
    temp[i] = 100 + i;
  }
  *p = temp;
}

void printArray(int ** pArray, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", (*pArray)[i]);
  }
}

void freeSpace(int * pArray, int len) {
  if (pArray != NULL) {
    free(pArray);
    pArray = NULL;
  }
}

void test01() {
  int *p = NULL;
  int len = 5;
  allocateSpace(&p, len);

  printArray(&p, len);

  freeSpace(p, len);

  if (p == NULL) {
    printf("空指针\n");
  } else {
    printf("野指针\n");
  }
}

int main() {
  test01();
  return EXIT_SUCCESS;
}