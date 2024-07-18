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
void insert_DynamicArray(struct dynamicArray * array, int pos, void * data) {
  if (array == NULL) {
    return;
  }
  if (data == NULL) {
    return;
  }
  // 无效位置，插入最后
  if(pos<0||pos>array->m_size) {
    pos = array->m_size;
  }

  // 判断是否满了，如果满了，动态扩展
  if (array->m_size >= array->m_capacity) {
    int newCapacity = array->m_capacity*2;

    void ** newSpace = malloc(sizeof (void *)*newCapacity);

    memcpy(newSpace, array->pAddr, sizeof (void*)*array->m_capacity);

    free(array->pAddr);

    array->pAddr = newSpace;

    array->m_capacity = newCapacity;
  }

  // 移动元素，插入新元素
  for (int i = array->m_capacity; i >= pos ; i--) {
    // 数据向后移动
    array->pAddr[i+1] = array->pAddr[i];
  }
  array->m_size++;
  array->pAddr[pos] = data;
}

// 遍历数组
void foreach_dynamic_array(struct dynamicArray * array, void(*myPrint) (void*)) {
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

struct Person {
    char name[64];
    int age;
};

void myPrintPerson (void * person) {
  struct Person *p = person;
  printf("name: %s, age: %d \n", p->name, p->age);
}

int main() {
  struct dynamicArray * array = init_DynamicArray(2);
  printf("before: capacity: %d, size: %d \n", array->m_capacity, array->m_size);

  struct Person p1 = {"a", 1};
  struct Person p2 = {"a", 2};
  struct Person p3 = {"a", 3};
  struct Person p4 = {"a", 4};
  struct Person p5 = {"a", 5};

  insert_DynamicArray(array,0, &p1);
  insert_DynamicArray(array,1, &p2);
  insert_DynamicArray(array,-1, &p3);
  insert_DynamicArray(array,0, &p4);
  insert_DynamicArray(array,2, &p5);
  printf("after: capacity: %d, size: %d \n", array->m_capacity, array->m_size);
  foreach_dynamic_array(array, myPrintPerson);

  return EXIT_SUCCESS;
}