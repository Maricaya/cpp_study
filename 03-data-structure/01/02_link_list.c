#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 节点结构体
struct LinkNode {
    // 数据域
    void *data;
    // 指针域
    struct LinkNode *next;
};

// 链表结构体
struct LList {
    struct LinkNode pHeader; // 头节点
    int m_size; // 链表长度
};

typedef void *LinkList;

LinkList init_LinkList() {
  struct LList *myList = malloc(sizeof(struct LList));

  if (myList == NULL) {
    return NULL;
  }

  myList->pHeader.data = NULL;
  myList->pHeader.next = NULL;
  myList->m_size = 0;

  return myList;
};

void insert_LinkList(LinkList list, int pos, void *data) {
  if (list == NULL || data == NULL) {
    return;
  }
  struct LList *myList = list;
  if (pos < 0 || pos > myList->m_size) {
    pos = myList->m_size;
  }
  struct LinkNode *pCurrent = &myList->pHeader;

  for (int i = 0; i < pos; i++) {
    pCurrent = pCurrent->next;
  }
  struct LinkNode *newNode = malloc(sizeof(struct LinkNode));

  newNode->data = data;

  // 建立节点关系
  newNode->next = pCurrent->next;
  pCurrent->next = newNode;
  myList->m_size++;
}

// 遍历链表
void foreach_LinkList(LinkList list, void(*myPrint)(void *)) {
  if (list == NULL) {
    return;
  }
  struct LList *myList = list;

  struct LinkNode *pCurrent = myList->pHeader.next;

  while (pCurrent != NULL) {
    myPrint(pCurrent->data);
    pCurrent = pCurrent->next;
  }
}

void myPrintPerson(void *person);

void delete_LinkList(LinkList list, int pos) {
  if (list == NULL) {
    return;
  }

  struct LList *myList = list;
  if (pos < 0 || pos > myList->m_size) {
    return;
  }

  struct LinkNode *pCurrent = &myList->pHeader; //NULL
  struct LinkNode *pPrev = &myList->pHeader; // NULL

  for (int i = 0; i <= pos; i++) {
    pPrev = pCurrent;
    pCurrent = pCurrent->next;
  }

  pPrev->next = pCurrent->next;
  free(pCurrent);
  myList->m_size--;
}

void clear_LinkList(LinkList list) {
  struct LList *myList = list;

  struct LinkNode *pCurrent = myList->pHeader.next;

  while (pCurrent != NULL) {
    struct LinkNode *temp = pCurrent;
    pCurrent = pCurrent->next;
    free(temp);
    myList->m_size--;
  }
  myList->pHeader.next=NULL;
}

void destroy_LinkList(LinkList list) {
  if (list == NULL) {
    return;
  }
  clear_LinkList(list);
  free(list);
}

// ******** test ********
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
  struct Person p1 = {"a", 1};
  struct Person p2 = {"a", 2};
  struct Person p3 = {"a", 3};
  struct Person p4 = {"a", 4};
  struct Person p5 = {"a", 5};

  LinkList myList = init_LinkList();

  insert_LinkList(myList, 0, &p1);
  insert_LinkList(myList, 1, &p2);
  insert_LinkList(myList, 2, &p3);
  insert_LinkList(myList, 3, &p4);
  insert_LinkList(myList, 4, &p5);

  printf("after insert\n");
  foreach_LinkList(myList, myPrintPerson);

  // delete
  delete_LinkList(myList, 0);
  printf("after delete\n");
  foreach_LinkList(myList, myPrintPerson);

  // clear
  clear_LinkList(myList);
  printf("after clear\n");
  foreach_LinkList(myList, myPrintPerson);

  // destroy
  destroy_LinkList(myList);
  printf("after destroy\n");
  foreach_LinkList(myList, myPrintPerson);


  return EXIT_SUCCESS;
}