#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reversePrint(char * p) {
  if (*p == '\0') {
    return;
  }
  reversePrint(p+1);
  printf("%c", *p);
}

void test01(char string[]) {
  printf("%s\n", string);
  reversePrint(string);
  printf("\n");
}

int fibonacci(int pos) {
  if (pos == 1 || pos == 2) {
    return 1;
  }
  return fibonacci(pos-1) + fibonacci(pos-2);
}

void test02() {
  int res = fibonacci(10);
  printf("%d\n", res);
}


int main() {
  char string[]  = "abcd";
  test01(string);
  test02();
  return EXIT_SUCCESS;
}