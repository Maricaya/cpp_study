#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

struct SStack {
    void *data[MAX];

    int m_Size;
};

typedef void *SeqStack;

// 初始化栈
SeqStack init_SeqStack() {
  struct SStack *myStack = malloc(sizeof(struct SStack));

  if (myStack == NULL) {
    return NULL;
  }

  // 初始化数组
  memset(myStack->data, 0, sizeof(void *) * MAX);
  // 初始化
  myStack->m_Size = 0;

  return myStack;
}

// 入栈
void push_SeqStack(SeqStack stack, void *data) {
  // 入栈本质 __ 数组尾插
  if (stack == NULL || data == NULL) {
    return;
  }
  struct SStack *myStack = stack;
  if (myStack->m_Size == MAX) {
    return;
  }
  myStack->data[myStack->m_Size] = data;
  myStack->m_Size++;
}

// 出栈
void pop_SeqStack(SeqStack stack) {
  // 数组尾删
  if (stack == NULL) {
    return;
  }
  struct SStack *myStack = stack;
  if (myStack->m_Size == 0) {
    return;
  }
  myStack->data[myStack->m_Size - 1] = NULL;
  myStack->m_Size--;
}

// 返回栈顶
void *top_SeqStack(SeqStack stack) {
  if (stack == NULL) {
    return NULL;
  }
  struct SStack * myStack = stack;
  if (myStack->m_Size == 0) {
    return NULL;
  }
  void *data = myStack->data[myStack->m_Size - 1];
  return data;
}

// 返回栈大小
int size_SeqStack(SeqStack stack) {
  if (stack == NULL) {
    return -1;
  }
  struct SStack * myStack = stack;
  return myStack->m_Size;
}

// 判断栈是否为空
int isEmpty_SeqStack(SeqStack stack) {
  if (stack == NULL) {
    return 1; // 是空栈
  }
  struct SStack * myStack = stack;
  if (myStack->m_Size==0) {
    return 1;
  }
  return 0;
}

// 销毁栈
void destroy_SeqStack(SeqStack stack) {
  if (stack == NULL) {
    return;
  }
  free(stack);
}

struct Person {
    char name[64];
    int age;
};

int main() {
  SeqStack myStack = init_SeqStack();
  struct Person p1 = {"a", 1};
  struct Person p2 = {"a", 2};
  struct Person p3 = {"a", 3};
  struct Person p4 = {"a", 4};
  struct Person p5 = {"a", 5};

  push_SeqStack(myStack, &p1);
  push_SeqStack(myStack, &p2);
  push_SeqStack(myStack, &p3);
  push_SeqStack(myStack, &p4);
  push_SeqStack(myStack, &p5);

  printf("number of the elements in stack is : %d\n", size_SeqStack(myStack));

  // 栈不为空，查看栈顶元素，并且出栈
  while (isEmpty_SeqStack(myStack )== 0) {
    struct Person *p = top_SeqStack(myStack);
    printf("name: %s, age: %d \n", p->name, p->age);

    pop_SeqStack(myStack);
  }

  printf("number of the elements in stack is : %d\n", size_SeqStack(myStack));

  destroy_SeqStack(myStack);

  return EXIT_SUCCESS;
}