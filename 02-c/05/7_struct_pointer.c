#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 结构体嵌套一级指针练习
struct Person {
    char *name;
    int age;
};

//void allocateSpace(struct Person **pArray) {
//  pArray = malloc((sizeof Person *p) * 4);
//}

struct Person ** allocateSpace(int len) {
  struct Person ** temp = malloc(sizeof (struct Person*) *len);
  for (int i = 0; i < len; i++) {
    temp[i] = malloc(sizeof (struct Person));

    temp[i]->name = malloc(sizeof (char)*64);
    sprintf(temp[i]->name, "name_%d", i+1);
    temp[i]->age = 18+i;
  }
  return temp;
}

void printPerson(struct Person **pArray, int len) {
  for (int i = 0; i < len; i++) {
    printf("name: %s, age: %d\n", pArray[i]->name, pArray[i]->age);
  }
}

void freeSpace(struct Person **pPerson, int len) {
  if (pPerson == NULL || len < 0) {
    return;
  }
  for (int i = 0; i < len; i++) {
    if (pPerson[i]->name != NULL) {
      free(pPerson[i]->name);
      pPerson[i]->name = NULL;
    }
    free(pPerson[i]);
    pPerson[i] = NULL;
  }
  free(pPerson);
  pPerson = NULL;
}

void test01() {
  struct Person **pArray = NULL;
  int len = 3;
  pArray = allocateSpace(len);
  printPerson(pArray, len);
  freeSpace(pArray, len);
}



int main() {
  test01();
  return EXIT_SUCCESS;
}