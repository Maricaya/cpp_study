#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for DFS
struct Stack {
    struct Node* nodes[MAX];
    int top;
};

// Function to create a new node
struct Node* newNode(char data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Initialize the stack
void initStack(struct Stack* stack) {
  stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, struct Node* node) {
  if (stack->top < MAX - 1) {
    stack->nodes[++stack->top] = node;
  }
}

// Pop an element from the stack
struct Node* pop(struct Stack* stack) {
  if (!isEmpty(stack)) {
    return stack->nodes[stack->top--];
  }
  return NULL;
}

// DFS traversal
void DFS(struct Node* root) {
  struct Stack stack;
  initStack(&stack);

  push(&stack, root);

  while (!isEmpty(&stack)) {
    struct Node* node = pop(&stack);

    if (node != NULL) {
      printf("%c ", node->data);

      // Push right child first so that left child is processed first
      if (node->right != NULL) {
        push(&stack, node->right);
      }
      if (node->left != NULL) {
        push(&stack, node->left);
      }
    }
  }
}

int main() {
  // Create the tree shown in the image
  struct Node* root = newNode('A');
  root->left = newNode('B');
  root->right = newNode('F');
  root->left->left = newNode('C');
  root->left->left->left = newNode('D');
  root->left->left->right = newNode('E');
  root->right->left = newNode('G');
  root->right->left->left = newNode('H');

  printf("DFS Traversal: ");
  DFS(root);
  printf("\n");

  return 0;
}
