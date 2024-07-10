#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 结构体嵌套二级指针练习
struct Teacher {
    char *name;
    char **students;
};

void allocateSpace(struct Teacher *** teachers, int len) {
  struct Teacher **temp = malloc(sizeof(struct Teacher *) * len);
  for (int i = 0; i < len; i++) {
    temp[i] = malloc(sizeof(struct Teacher));

    temp[i]->name = malloc(sizeof(char) * 64);
    sprintf(temp[i]->name, "teacher_name_%d", i + 1);

    // 给学生的数组分配内存
    temp[i]->students = malloc(sizeof(char *) * 4);
    for (int j = 0; j < 4; j++) {
      temp[i]->students[j] = malloc(sizeof(char) * 64);
      sprintf(temp[i]->students[j], "student_name_%d_%d", i + 1, j + 1);
    }
  }
  *teachers = temp;
}

void printPerson(struct Teacher **pArray, int len) {
  for (int i = 0; i < len; i++) {
    printf("teacher name: %s", pArray[i]->name);
    for (int j = 0; j < 4; j++) {
      printf("student name: %s ", pArray[i]->students[j]);
    }
    printf("\n");
  }
}

void freeSpace(struct Teacher **pArray, int len) {
  if (pArray == NULL || len < 0) {
    return;
  }
  for (int i = 0; i < len; i++) {
    if (pArray[i]->name != NULL) {
      free(pArray[i]->name);
      pArray[i]->name = NULL;
    }
    for (int j = 0; j < 4; j++) {
      if (pArray[i]->students[j] != NULL) {
        free(pArray[i]->students[j]);
        pArray[i]->students[j] = NULL;
      }
    }
    if (pArray[i]->students != NULL) {
      free(pArray[i]->students);
      pArray[i]->students = NULL;
    }

    if (pArray[i] != NULL) {
      free(pArray[i]);
      pArray[i] = NULL;
    }
  }
  free(pArray);
  pArray = NULL;
}

void test01() {
  struct Teacher **pArray = NULL;
  int len = 3;
  allocateSpace(&pArray, len);
  printPerson(pArray, len);
  freeSpace(pArray, len);
}


int main() {
  test01();
  return EXIT_SUCCESS;
}