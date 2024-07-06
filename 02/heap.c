#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_a = 1000;

int *getSpace() {
  int *p = malloc(sizeof(int) * 5);
  if (p == NULL) {
    return 0;
  }
  for (int i = 0; i < 5; i++) {
    p[i] = i + 100;
  }
  return p;
}

void test01() {
  int * p = getSpace();
  for (int i = 0; i < 5; i++) {
    printf("%d\n", p[i]);
  }
  // 手动开辟 手动释放
  free(p);
  p = NULL;
}

// 注意事项
void allocateSpace(char ** pp) {
  char * temp = malloc(100);
  memset(temp, 0, 100);
  strcpy(temp, "hello world");
  *pp = temp;
}

void test02() {
  char * p = NULL;
  allocateSpace(&p);
  printf("%s\n", p);
}


int main1() {
  test02();
  return EXIT_SUCCESS;
}
