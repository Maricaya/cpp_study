#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

struct LinkNode {
    struct LinkNode *next;
};

struct LList {
    struct LinkNode pHeader;
    int m_Size;
};

typedef void *LinkList;

LinkList init_LinkList() {
  struct LList *myList = malloc(sizeof(struct LList));

  if (myList == NULL) {
    return NULL;
  }
  myList->pHeader.next = NULL;
  myList->m_Size = 0;

  return myList;
}

//  插入
void insert_LinkList(LinkList list, int pos, void *data) {
  if (list == NULL || data == NULL) {
    return;
  }
  struct LList *myList = list;
  if (pos < 0 || pos > myList->m_Size -1) {
    pos = myList->m_Size;
  }
  // 用户数据前4个字节，由我们使用
  struct LinkNode *myNode = data;

  // 找插入节点的前驱节点
  struct LinkNode *pCurrent = &myList->pHeader;

  for (int i = 0; i < pos; i++) {
    pCurrent = pCurrent->next;
  }
  // pCurrent 是前驱节点位置
  myNode->next = pCurrent->next;
  pCurrent->next = myNode;
  myList->m_Size++;
}

void foreach_LinkList(LinkList list, void(*myPrint)(void *)) {
  if (list == NULL) {
    return;
  }

  struct LList *myList = list;
  struct LinkNode *myNode = myList->pHeader.next;

  while (myNode != NULL) {
    myPrint(myNode);
    myNode = myNode->next;
  }
}

void clear_LinkList(LinkList list) {
  if (list == NULL) {
    return;
  }
  struct LList *myList = list;

  myList->pHeader.next = NULL; // Set the head node's next pointer to NULL
  myList->m_Size = 0; // Reset the size of the list to 0
}

// Destroy the linked list
void destroy_LinkList(LinkList list) {
  if (list == NULL) {
    return;
  }
  clear_LinkList(list);
  free(list);
}

// ******** test ********
struct Person {
    void* node;
    char name[64];
    int age;
};

void myPrintPerson(void *person) {
  struct Person *p = person;
  printf("name: %s, age: %d \n", p->name, p->age);
}

void test1() {
  // 初始化列表
  LinkList myList = init_LinkList();

  struct Person p1 = {NULL, "aaa", 10};
  struct Person p2 = {NULL, "aaa", 20};
  struct Person p3 = {NULL, "aaa", 30};
  struct Person p4 = {NULL, "aaa", 40};
  struct Person p5 = {NULL, "aaa", 50};

  insert_LinkList(myList, 0, &p1);
  insert_LinkList(myList, 0, &p2);
  insert_LinkList(myList, -1, &p3);
  insert_LinkList(myList, 0, &p4);
  insert_LinkList(myList, 0, &p5);

  foreach_LinkList(myList, myPrintPerson);

  // Clean up
  clear_LinkList(myList);

  printf("After clear:\n");
  foreach_LinkList(myList, myPrintPerson);

  destroy_LinkList(myList);
}

int main() {
  test1();
  return EXIT_SUCCESS;
}