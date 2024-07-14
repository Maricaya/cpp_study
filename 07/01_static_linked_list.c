#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 数组缺陷：静态空间，一旦分配内存就不可以动态扩展
// 如果分配过多，造成了资源浪费
// 对于头部插入删除的效率低

/*
 * 数组维护的空间更小，
 * 数组查找更快
 *
 * 链表的分类一：
 *  静态链表，在栈上分配内存
 *  动态链表，在堆区分配内存
 * 链表的分类二：
 *  单向链表，双向链表
 *  单向循环链表，双向循环链表
 * */

// 节点的结构体
struct LinkNode {
  int num; // 数据域
  struct LinkNode * next; // 指针域
};

// 静态列表
void test01() {
  // 创建节点
  struct LinkNode node1 = {10, NULL};
  struct LinkNode node2 = {20, NULL};
  struct LinkNode node3 = {30, NULL};
  struct LinkNode node4 = {40, NULL};
  struct LinkNode node5 = {50, NULL};

  // 建立关系
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;

  // 遍历链表
  struct LinkNode * pCurrent = &node1;

  while (pCurrent != NULL) {
    printf("%d\n", pCurrent -> num);
    pCurrent = pCurrent -> next;
  }


}

int main() {
  test01();
  return EXIT_SUCCESS;
}