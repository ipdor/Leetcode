//https://leetcode.com/problems/design-linked-list/description/
/*
 * 有种改进办法：
 * 1.节点结构体增加构造函数,赋值和new一步完成
 * 2.MyLinkedList增加size，方便检查index合法性,不需要遍历就知道是否合法
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.md
 */
class MyLinkedList {
private:
    class Node
    {
    private:
        int val;
        Node *next;
        friend class MyLinkedList;
    };
    Node *head;

public:
    MyLinkedList() {
        head = new Node();
        head->val = -1;
        head->next = nullptr;
    }
    
    int get(int index) {
        Node *node = this->head;
        for (int i = 0; i < index && node; i++,node = node->next);

        if (!node || !node->next)
        {
            return -1;
        }
        return node->next->val;
    }
    
    void addAtHead(int val) {
        Node *oldHead = head->next;
        Node *node = new Node();
        node->val = val;
        node->next = oldHead;
        head->next = node;
    }
    
    void addAtTail(int val) {
        Node *node = this->head;
        while (node->next)
        {
            node = node->next;
        }
        Node *newNode = new Node();
        newNode->val = val;
        newNode->next = nullptr;
        node->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node *node = this->head;
        for (int i = 0; i < index && node; i++,node = node->next);
        if (!node)
        {
            return;
        }
        Node *newNode = new Node();
        newNode->val = val;
        newNode->next = node->next;
        node->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        Node *node = this->head;
        for (int i = 0; i < index && node; i++,node = node->next);
        if (!node || !node->next)
        {
            return;
        }
        Node *nodeNext = node->next->next;
        delete node->next;
        node->next = nodeNext;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */