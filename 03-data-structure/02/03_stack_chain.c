#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 节点结构体
struct stackNode {
    struct stackNode *next;
};

// 栈的结构体
struct LStack {
    struct stackNode pHeader;
    int m_size;
};

typedef void *LinkStack;

// 初始化
LinkStack init_LinkStack() {
  struct LStack *myStack = malloc(sizeof(struct LStack));

  if (myStack == NULL) {
    return NULL;
  }
  myStack->pHeader.next = NULL;
  myStack->m_size = 0;

  return myStack;
}

// 入栈
void push_LinkStack(LinkStack stack, void *data) {
  // 头插
  if (stack == NULL || data == NULL) {
    return;
  }
  struct LStack *myStack = stack;
  // 将用户数据取出前4个字节
  struct stackNode *myNode = data;

  // 更改指针指向
  myNode->next = myStack->pHeader.next;
  myStack->pHeader.next = myNode;

  myStack->m_size++;
}

// 出栈
void pop_LinkStack(LinkStack stack) {
  // 头删
  if (stack == NULL) {
    return;
  }
  struct LStack *myStack = stack;
  if (myStack->m_size == 0) {
    return;
  }
  // 更改指针指向
  // 缓存第一个有数据的节点
  struct stackNode *pFirst = myStack->pHeader.next;

  myStack->pHeader.next = pFirst->next;

  // 更新栈大学
  myStack->m_size--;
}

// 栈顶元素
void *top_LinkStack(LinkStack stack) {
  if (stack == NULL) {
    return NULL;
  }
  struct LStack *myStack = stack;
  if (myStack->m_size == 0) {
    return NULL;
  }
  return myStack->pHeader.next;
}

// 返回栈个数
int size_LinkStack(LinkStack stack) {
  if (stack == NULL) {
    return -1;
  }
  struct LStack *myStack = stack;
  return myStack->m_size;

}

int isEmpty_LinkStack(LinkStack stack) {
  if (stack == NULL) {
    return -1;
  }
  struct LStack *myStack = stack;
  return myStack->m_size == 0;

}

void destroy_LinkStack(LinkStack stack) {
  if (stack == NULL) {
    return;
  }
  free(stack);
  stack = NULL;
}

struct Person {
    void *node;
    char name[64];
    int age;
};

void test() {
  LinkStack myStack = init_LinkStack();
  struct Person p1 = {NULL, "a", 1};
  struct Person p2 = {NULL, "b", 2};
  struct Person p3 = {NULL, "c", 3};
  struct Person p4 = {NULL, "d", 4};
  struct Person p5 = {NULL, "e", 5};

  push_LinkStack(myStack, &p1);
  push_LinkStack(myStack, &p2);
  push_LinkStack(myStack, &p3);
  push_LinkStack(myStack, &p4);
  push_LinkStack(myStack, &p5);

  printf("number of the elements in stack is : %d\n", size_LinkStack(myStack));

  // 栈不为空，查看栈顶元素，并且出栈
  while (isEmpty_LinkStack(myStack) == 0) {
    struct Person *p = top_LinkStack(myStack);
    printf("name: %s, age: %d \n", p->name, p->age);

    pop_LinkStack(myStack);
  }

  printf("number of the elements in stack is : %d\n", size_LinkStack(myStack));

  destroy_LinkStack(myStack);
}

int test2(char *str) {
  char left = '(';
  char right = ')';
  LinkStack myStack = init_LinkStack();
  struct stackNode node;
  while (*str != '\0') {
    if (*str == left) {
      push_LinkStack(myStack, &node);
    }
    if (*str == right) {
      if (size_LinkStack(myStack) > 0) {
        pop_LinkStack(myStack);
      } else {
        destroy_LinkStack(myStack);
        printf("）没有匹配到（\n");
//        break;
        return 0;
      }
    }
    str++;
  }
  int size = size_LinkStack(myStack);
  destroy_LinkStack(myStack);
  return size == 0;
}

void test3(char *p) {

  LinkStack myStack = init_LinkStack();
  struct stackNode node;
  while (*p != '\0') {
    if (isdigit(*p)) {
      printf("%d", *p);
    }
    if (isalpha(*p)) {
      push_LinkStack(myStack, &p);
    }
    p++;
  }
  pop_LinkStack(myStack);
//  printf("%c",a);
}

int main() {
  char *str = "abcd()";
  int ans = test2(str);
  printf("%s: %d\n", str, ans);

  char *str1 = "5 + 4";
  test3(str1);
  printf("%s: \n", str1);



  return EXIT_SUCCESS;
}
