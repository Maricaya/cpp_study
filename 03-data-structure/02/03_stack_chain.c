#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 节点结构体
struct stackNode {
    struct stackNode *next;
};

// 栈的结构体
struct LStack {
    struct stackNode *pHeader;
    int m_size;
};

typedef void *LinkStack;

// 初始化
LinkStack init_LinkStack() {
}

// 入栈
LinkStack push_LinkStack(LinkStack stack, void *data) {
}

// 出栈
LinkStack pop_LinkStack(LinkStack stack, void *data) {
}

// 栈顶元素
void * top_LinkStack(LinkStack stack) {

}

// 返回栈个数
int size_LinkStack(LinkStack stack) {

}

int isEmpty_LinkStack(LinkStack stack) {

}

void destroy_LinkStack(LinkStack stack) {

}

int main() {
  return EXIT_SUCCESS;
}
