#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

// 初始化链表
struct LinkNode *initLinkList() {
  // 创建头节点
  struct LinkNode *pHeader = malloc(sizeof(struct LinkNode));

  if (pHeader == NULL) {
    return NULL;
  }

  // 初始化头节点
  pHeader->num = -1; // 头节点，不维护数据域
  pHeader->next = NULL;

  // 记录尾节点的位置,方便插入新的数据
  struct LinkNode *pTail = pHeader;
  int val = -1;
  int array[] = {1, 2, 3};
  while (1) {
    printf("请初始化链表，如果输入-1代表结束\n");
    //让用户初始化几个节点，如果用户输入的是-1，代表插入结束
    scanf("%d", &val);
    if (val == -1) {
      break;
    }
    // 如果不是-1，插入节点到链表中
    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    newNode->num = val;
    newNode->next = NULL;

    // 更新指针的指向
    pTail->next = newNode;
    // 更新新的尾节点的指向
    pTail = newNode;
  }

  return pHeader;
}

void foreach_LinkList(struct LinkNode *pHeader) {
  if (pHeader == NULL) {
    return;
  }
  struct LinkNode *pCurrent = pHeader->next;


  while (pCurrent != NULL) {
    printf("%d\n", pCurrent->num);
    pCurrent = pCurrent->next;
  }
}

void insert_LinkList(struct LinkNode *pHeader, int oldVal, int newVal) {
  if (pHeader == NULL) {
    return;
  }


  struct LinkNode *pPrev = pHeader;
  struct LinkNode *pCurrent = pHeader->next;

  while (pCurrent != NULL) {
    if (pCurrent->num == oldVal) {
      break;
    }
    // 如果没找到对应的位置，辅助指针向后移动
    pPrev = pCurrent;
    pCurrent = pCurrent->next;
  }
  // 创建新的节点
  struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
  newNode->num = newVal;
  newNode->next = NULL;

  //建立关系
  newNode->next=pCurrent;
  pPrev->next=newNode;
}

int main() {
  struct LinkNode *pHeader = initLinkList();

  printf("遍历链表结果为:\n");
  foreach_LinkList(pHeader);

  insert_LinkList(pHeader, 1, 100);

  printf("插入之后遍历链表结果为:\n");
  foreach_LinkList(pHeader);
  return 0;
}