#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mySortInt(void *data1, void *data2) {
  int *num1 = data1;
  int *num2 = data2;
  return *num1 < *num2;
}

void sort(
        void *pArray,
        int eleSize,
        int len,
        int(*mySort)(void *, void *)
) {
  char *p = pArray;
  for (int i = 0; i < len; i++) {
    int min_i = i;
    for (int j = i; j < len; j++) {
      if (mySort(p + eleSize * j, p + eleSize * min_i)) {
        min_i = j;
      }
    }

    if (min_i != i) {
      // swap elements
      char temp[eleSize];
      memcpy(temp, p + eleSize * i, eleSize);
      memcpy(p + eleSize * i, p + eleSize * min_i, eleSize);
      memcpy(p + eleSize * min_i, temp, eleSize);
    }
  }
}

void test01() {
  int arr[] = {1, 100, 50, 80, 2};
  int len = sizeof(arr) / sizeof(int);
  sort(arr, sizeof(int), len, mySortInt);
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }
}

struct Person {
    char name[64];
    int age;
};

int comparePerson(void *data1, void *data2) {
  struct Person *p1 = data1;
  struct Person *p2 = data2;

  return p1->age - p2->age;
}

void printPersonArray(void *data) {
  struct Person *p = data;
  printf("name: %s, age: %d\n", p->name, p->age);
}

void test02() {
  struct Person personArray[] = {
          {"a1", 1},
          {"a2", 1111},
          {"a3", 2222},
          {"a4", 444},
          {"a5", 5},
  };

  int len = sizeof(personArray) / sizeof(struct Person);

  sort(personArray, sizeof(struct Person), len, comparePerson);

  for (int i = 0; i < len; i++) {
    printf("name: %s, age: %d\n", personArray[i].name, personArray[i].age);  // Corrected printing
  }
}

int main() {
  test02();
  return EXIT_SUCCESS;
}