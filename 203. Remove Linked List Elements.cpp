//https://leetcode.com/problems/remove-linked-list-elements/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (!head)
        {
            return head;
        }
        //构造一个新节点放在head前面，这样不用单独处理head->val==val的情况
        ListNode node(0);
        node.next = head;
        head = &node;
        
        ListNode *ptr = head, *fastPtr = ptr->next;
        
        while (fastPtr)
        {
            if (fastPtr->val == val)
            {
                ptr->next = fastPtr->next;
                delete fastPtr;
            }
            else
                ptr = fastPtr;
            fastPtr = ptr->next;
        }
        fastPtr = head->next;
        delete head;
        return fastPtr;
    }
};