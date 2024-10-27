//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode newHead(-1, head), *late = &newHead, *tail = &newHead, *node=nullptr;
        for (int i = 0; tail->next; i++)
        {
            if (i>=n)
                late = late->next;
            tail = tail->next;
        }
        node = late->next;
        late->next = node->next;
        delete node;
        return newHead.next;
    }
};