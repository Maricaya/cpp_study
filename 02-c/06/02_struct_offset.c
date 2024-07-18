#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

struct Teacher {
    char a; // 0~3
    int b; // 4~7
};

void test01() {
  struct Teacher t1;
  struct Teacher *p = &t1;

  printf("b的属性偏移量为: %d\n", (int) &(p->b) - (int) p);

  printf("b的属性偏移量为: %d\n", offsetof(struct Teacher, b));
}

// 通过偏移量 操作内存
void test02() {
  struct Teacher t1 = {'a', 10};
  printf("t1.b = %d\n", *(int *) ((char *) &t1 + offsetof(struct Teacher, b)));
  printf("t1.b = %d\n", *(int *) ((int *) &t1 + 1));
}

struct Teacher2 {
    char a; // 0~3
    int b; // 4~7
    struct Teacher c;
};

void test03() {
  struct Teacher2 t2 = {'a', 10, 'b', 5};

  int offset1 = offsetof(struct Teacher2, c);
  int offset2 = offsetof(struct Teacher, b);

  printf("t1.c.a = %c\n", *(int *) ((char *) &t2 + offset1));
  printf("t1.c.b = %d\n", *(int *) ((char *) &t2 + offset1+ offset2));

  printf("t2.c.a = %c\n", *(int *) ((int *) &t2 + 2));

  printf("t2.c.b = %d\n", ((struct Teacher*)((char*)&t2 + offset1)) -> b);


}

int main() {
  test03();
  return EXIT_SUCCESS;
}