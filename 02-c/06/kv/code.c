#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Encryption:
 * # 35 -> short
 * 0000 0000 0010 0011 <<4
 * 0000 0010 0011 0000 | 1000 0000 0000 0000
 * 1000 0010 0011 0000 Add random number 0000 ~ 1111 (0~15) rand() % 16
 * 1000 0010 0011 0101
 */
void codeFile(char *sourceFilePath, char *destFilePath) {
  FILE *file1 = fopen(sourceFilePath, "r");
  FILE *file2 = fopen(destFilePath, "w");

  if (file1 == NULL || file2 == NULL) {
    perror("Failed to open files");
    return;
  }

  int mask = 0b1000000000000000;
  srand(time(NULL)); // Initialize random seed

  char c;
  // 逐字符读取
  while ((c = fgetc(file1)) != EOF) {
    int temp = (int) c;
    temp = ((temp << 4) | mask) + (rand() % 16);
    fprintf(file2, "%hd", temp);
  }

  fclose(file1);
  fclose(file2);
}

/*
 * Decryption:
 * 1000 0010 0011 0101 <<1
 * 000 0010 0011 01010 >>5
 * 0000 0000 0010 0011
 */
void decodeFile(char *f1, char *f2) {
  FILE *file1 = fopen(f1, "r");
  FILE *file2 = fopen(f2, "w");

  if (file1 == NULL || file2 == NULL) {
    perror("Failed to open files");
    return;
  }

  int temp;
  while (!feof(file1)) {
    // todo ??
    fscanf(file1, "%hd", &temp);

    temp = temp << 1;
    temp = temp >> 5;
    char ch = (char)temp;
    fputc(ch, file2);
  }

  fclose(file1);
  fclose(file2);
}

int main() {
  char *filePath1 = "./06/kv/config.txt";
  char *filePath2 = "./06/kv/encode_config.txt";
  char *filePath3 = "./06/kv/decode_config.txt";

  codeFile(filePath1, filePath2);
  decodeFile(filePath2, filePath3);

  return EXIT_SUCCESS;
}
