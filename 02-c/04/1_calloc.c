#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// calloc
// realloc
void test01() {
  // int *p = malloc(sizeof (int)*10);
  int *p = calloc(10, sizeof(int)); // calloc 分配在堆区，与malloc不同的是 calloc 会初始化数据为0

  for (int i = 0; i < 10; i++) {
    printf("%d\n", p[i]);
  }

  if (p != NULL) {
    free(p);
    p = NULL;
  }
}

// realloc 重新分配内存
void test02() {
  int *p = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++) {
    p[i] = i + 100;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d\n", p[i]);
  }
  printf("%d\n", p);

  // 如果重新分配的内存比原来大，那么不会初始化新空间为0
  p = realloc(p, sizeof(int) * 20);
  for (int i = 0; i < 10; i++) {
    printf("%d\n", p[i]);
  }
  printf("%d\n", p);
}


int main() {
  test02();
  return EXIT_SUCCESS;
}