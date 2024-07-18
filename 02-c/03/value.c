#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void changeValue(int *a) {
  *a = 1000;
}

void test01() {
  int a = 10;
  int *p = &a;
  *p = 100;
  printf("%d\n", a);
  int a2 = 10;
  changeValue(&a2);
  printf("%d\n", a2);
}

int main() {
  test01();
  return EXIT_SUCCESS;
}