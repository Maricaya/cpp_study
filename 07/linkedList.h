struct LinkNode {
    int num;
    struct LinkNode *next;
};
// 初始化链表
struct LinkNode * initLinkList();

// 遍历链表
void foreach_LinkList(struct LinkNode * pHeader);

// 插入链表
void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal);