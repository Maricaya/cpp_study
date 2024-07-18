#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. 无法确定数据类型
// 2. 无法确定数据分配的具体位置
// 3. 不管创建在哪，不管是什么数据类型，放在内存中都会有地址

struct dynamicArray {
    void **pAddr;
    int m_capacity;
    int m_size;
};

// 初始化数组
struct dynamicArray *init_DynamicArray(int capacity) {
  if (capacity <= 0) {
    return NULL;
  }
  struct dynamicArray *array = malloc(sizeof(struct dynamicArray));

  if (array == NULL) {
    return NULL;
  }

  array->pAddr = malloc(sizeof(void *) * capacity);
  array->m_capacity = capacity;
  array->m_size = 0;

  return array;
}

// 插入shuz
void insert_DynamicArray(struct dynamicArray *array, int pos, void *data) {
  if (array == NULL) {
    return;
  }
  if (data == NULL) {
    return;
  }
  // 无效位置，插入最后
  if (pos < 0 || pos > array->m_size) {
    pos = array->m_size;
  }

  // 判断是否满了，如果满了，动态扩展
  if (array->m_size >= array->m_capacity) {
    int newCapacity = array->m_capacity * 2;

    void **newSpace = malloc(sizeof(void *) * newCapacity);

    memcpy(newSpace, array->pAddr, sizeof(void *) * array->m_capacity);

    free(array->pAddr);

    array->pAddr = newSpace;

    array->m_capacity = newCapacity;
  }

  // 移动元素，插入新元素
  for (int i = array->m_capacity; i >= pos; i--) {
    // 数据向后移动
    array->pAddr[i + 1] = array->pAddr[i];
  }
  array->m_size++;
  array->pAddr[pos] = data;
}

// 遍历数组
void foreach_dynamic_array(struct dynamicArray *array, void(*myPrint)(void *)) {
  if (array == NULL) {
    return;
  }
  if (myPrint == NULL) {
    return;
  }
  for (int i = 0; i < array->m_size; i++) {
    myPrint(array->pAddr[i]);
  }
}

// 删除数组 按位置删除
void removeByPos_DynamicArray(struct dynamicArray *array, int pos) {
  if (array == NULL) {
    return;
  }

  if (pos < 0 || pos > array->m_size - 1) {
    return;
  }

  for (int i = pos; i < array->m_size - 1; i++) {
    array->pAddr[i] = array->pAddr[i + 1];
  }
  array->m_size--;
}

void removeByValue_DynamicArray(struct dynamicArray *array, void *data, int(*myCompare)(void *, void *)) {
  if (array == NULL) {
    return;
  }
  if (data == NULL) {
    return;
  }
  for (int i = 0; i < array->m_size; i++) {
    if (myCompare(array->pAddr[i], data)) {
      removeByPos_DynamicArray(array, i);
    }
  }
}

// 销毁数组
void destroy_DynamicArray(struct dynamicArray *array) {
  if (array == NULL) {
    return;
  }
  if (array->pAddr != NULL) {
    free(array->pAddr);
    array->pAddr = NULL;
  }
  free(array);
}


struct Person {
    char name[64];
    int age;
};

void myPrintPerson(void *person) {
  struct Person *p = person;
  printf("name: %s, age: %d \n", p->name, p->age);
}

int myComparePerson(void *data1, void *data2) {
  struct Person *p1 = data1;
  struct Person *p2 = data2;

  return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int main() {
  struct dynamicArray *array = init_DynamicArray(2);
  printf("before: capacity: %d, size: %d \n", array->m_capacity, array->m_size);

  struct Person p1 = {"a", 1};
  struct Person p2 = {"a", 2};
  struct Person p3 = {"a", 3};
  struct Person p4 = {"a", 4};
  struct Person p5 = {"a", 5};

  insert_DynamicArray(array, 0, &p1);
  insert_DynamicArray(array, 1, &p2);
  insert_DynamicArray(array, -1, &p3);
  insert_DynamicArray(array, 0, &p4);
  insert_DynamicArray(array, 2, &p5);
  foreach_dynamic_array(array, myPrintPerson);
  printf("after: capacity: %d, size: %d \n", array->m_capacity, array->m_size);

  // 删除数据
  removeByPos_DynamicArray(array, 0);
  foreach_dynamic_array(array, myPrintPerson);
  printf("after: capacity: %d, size: %d \n", array->m_capacity, array->m_size);

  struct Person p5_1 = {"a", 5};
  // 删除数据
  removeByValue_DynamicArray(array, &p5_1, myComparePerson);
  foreach_dynamic_array(array, myPrintPerson);
  printf("after: capacity: %d, size: %d \n", array->m_capacity, array->m_size);

  destroy_DynamicArray(array);
  array = NULL;

  return EXIT_SUCCESS;
}