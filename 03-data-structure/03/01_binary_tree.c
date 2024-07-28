#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BinaryNode {
    // 数据域
    char ch;
    // 指针域
    struct BinaryNode *lChild;
    struct BinaryNode *rChild;
};

void printTree(struct BinaryNode *root) {
  if (root == NULL) {
    return;
  }
  printf("%c", root->ch);
  printTree(root->lChild);
  printTree(root->rChild);
}

// 叶子数数量
void numOfLeaf(struct BinaryNode *root, int *p) {
  if (root == NULL) {
    return;
  }
  if (root->lChild == NULL && root->rChild == NULL) {
    (*p)++;
  }
  numOfLeaf(root->lChild, p);
  numOfLeaf(root->rChild, p);
}

// 树的高度
int levelOfTree(struct BinaryNode *root) {
  if (root == NULL) {
    return 0;
  }
  int left = levelOfTree(root->lChild);
  int right = levelOfTree(root->rChild);
  return (left > right ? left : right) + 1;
}

// copy
struct BinaryNode *treeCopy(struct BinaryNode *root) {
  if (root == NULL) {
    return NULL;
  }
  struct BinaryNode *lChild = treeCopy(root->lChild);
  struct BinaryNode *rChild = treeCopy(root->rChild);
  struct BinaryNode *newTree = malloc(sizeof (struct BinaryNode));
  newTree->ch = root->ch;
  newTree->lChild = lChild;
  newTree->rChild = rChild;
  return newTree;
}

void freeTree(struct BinaryNode *root) {
  if (root == NULL) {
    return;
  }
  freeTree(root->lChild);
  freeTree(root->rChild);
  free(root);
}

void whileTree (struct BinaryNode *root) {
  struct BinaryNode* arr[] = {root};
  while (sizeof (a)) {


  }
}

void test01() {
  struct BinaryNode nodeA = {'A', NULL, NULL};
  struct BinaryNode nodeB = {'B', NULL, NULL};
  struct BinaryNode nodeC = {'C', NULL, NULL};
  struct BinaryNode nodeD = {'D', NULL, NULL};
  struct BinaryNode nodeE = {'E', NULL, NULL};
  struct BinaryNode nodeF = {'F', NULL, NULL};
  struct BinaryNode nodeG = {'G', NULL, NULL};
  struct BinaryNode nodeH = {'H', NULL, NULL};

  //建立关系
  nodeA.lChild = &nodeB;
  nodeA.rChild = &nodeF;

  nodeB.rChild = &nodeC;

  nodeC.lChild = &nodeD;
  nodeC.rChild = &nodeE;

  nodeF.rChild = &nodeG;
  nodeG.lChild = &nodeH;

  int num = 0;
  // 遍历
  whileTree(&nodeA);

  // 递归遍历
  numOfLeaf(&nodeA, &num);
  printf("num: %d\n", num);

  int level = levelOfTree(&nodeA);
  printf("level: %d\n", level);

  printf("---- nodeA---\n");
  printTree(&nodeA);
  struct BinaryNode *newTree = treeCopy(&nodeA);
  printf("\n---- newTreeA---\n");
  printTree(newTree);

  freeTree(newTree);
}

int main() {
  test01();
  return EXIT_SUCCESS;
}