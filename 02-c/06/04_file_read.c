#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 缓冲区优势
// 1. 提高硬件寿命
// 2. 提高读写效率
// 直接从内存进行读写

// 按照字符方式读写
// fgetc() fputc()
void test01() {
  // 写文件
  FILE *f_write = fopen("./06/test01.txt", "w+");

  if (f_write == NULL) {
    return;
  }
  char buf[] = "this is first test lalala";
  for (int i = 0; i < strlen(buf); i++) {
    fputc(buf[i], f_write);
  }

  fclose(f_write);

  // 读文件
  FILE *f_read = fopen("./06/test01.txt", "r");
  if (f_read == NULL) {
    return;
  }
  char ch;
  while ((ch = fgetc(f_read)) != EOF) {//end of file
    printf("%c", ch);
  }
}

// 按照行读写文件 fputs() fgets()
void test02() {
  // 写文件
  FILE *f_write = fopen("./06/test02.txt", "w");
  if (f_write == NULL) {
    return;
  }
  char *buf[] = {
          "鹅鹅鹅\n",
          "hahah\n",
          "hahah\n",
          "hahah\n",
  };
  for (int i = 0; i < 4; i++) {
    fputs(buf[i], f_write);
  }
  fclose(f_write);

  // 读文件
  FILE *f_read = fopen("./06/test02.txt", "r");
  if (f_read == NULL) {
    return;
  }
  while (!feof(f_read)) {
    char buf2[1024] = {0};
    fgets(buf2, 1024, f_read);
    printf("%s", buf2);
  }
}

// 按照块读写 fread() fwrite()
struct Hero {
    char name[64];
    int age;
};

void test03() {
  // 写文件，wb二进制方式
  FILE *f_write = fopen("./06/test03.txt", "wb");
  if (f_write == NULL) {
    return;
  }

  struct Hero heros[4] = {
          {"A", 18},
          {"B", 19},
          {"C", 20},
          {"D", 21},
  };

  for (int i = 0; i < 4; i++) {
    // 数据地址，块大小，块个数，文件指针
    fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
  }
  fclose(f_write);

  // 读文件
  FILE *f_read = fopen("./06/test03.txt",
                       "rb");
  if (f_read == NULL) {
    return;
  }
  struct Hero temp[4];
  fread(&temp, sizeof(struct Hero), 4, f_read);
  for (int i = 0; i < 4; i++) {
    printf("name: %s, age: %d \n", temp[i].name, temp[i].age);
  }
}

// 按照格式化读写文件 fprint() fscanf()
void test04() {
  FILE *f_write = fopen("./06/test04.txt", "w");
  if (f_write == NULL) {
    return;
  }
  fprintf(f_write, "hello world %d年%d月%d日", 2018, 7, 5);
  // 关闭文件
  fclose(f_write);

  // 读文件
  FILE *f_read = fopen("./06/test04.txt", "r");
  if (f_read==NULL) {
    return;
  }
  char buf[1024] = {0};
  while (!feof(f_read)) {
    fscanf(f_read, "%s", buf);
    printf("%s\n", buf);
  }
}

// 按照随机位置读写
void test05() {
  // 写文件，wb二进制方式
  FILE *f_write = fopen("./06/test05.txt", "wb");
  if (f_write == NULL) {
    return;
  }

  struct Hero heros[4] = {
          {"A", 18},
          {"B", 19},
          {"C", 20},
          {"D", 21},
  };

  for (int i = 0; i < 4; i++) {
    // 数据地址，块大小，块个数，文件指针
    fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
  }
  fclose(f_write);

  // 读取C数据
  FILE * f_read = fopen("./06/test05.txt", "rb");
  if (f_read == NULL) {
    // error 宏
    perror("文件打开失败");
    return;
  }
  // 创建临时结构体
  struct Hero temp;
  //改变文件光标位置
  //fseek(f_read, sizeof (struct Hero)*2, SEEK_SET);
  fseek(f_read, -(long)sizeof (struct Hero)*2, SEEK_END);

  printf("--- %lu ---\n", (sizeof (struct Hero)*2));

  rewind(f_read);// 将文件光标置首

  fread(&temp, sizeof (struct Hero), 1, f_read);
  printf("name: %s, age: %d", temp.name, temp.age);
}

int main() {
  test05();
  return EXIT_SUCCESS;
}