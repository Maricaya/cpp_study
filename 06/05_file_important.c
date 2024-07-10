#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 文件读写的注意事项
void test01() {
  FILE * f_read = fopen("./06/test01.txt", "r");
  if (f_read == NULL ) {
    return;
  }

  char ch;
  // 1. 注意事项1
  while ((ch = fgetc(f_read)) != EOF) {
    printf("%c", ch);
  }
  fclose(f_read);
}

// 2
struct Hero {
    char *name[64];
    // 如果属性开辟到堆区,不要存指针到文件中，
    // 要将指针指向到内容存放到文件中
    int age;
};

int main() {
  test01();
  return EXIT_SUCCESS;
}