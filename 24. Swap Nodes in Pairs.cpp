//https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode *newHead=nullptr, *newTail=nullptr, *now = head;
        while (now)
        {
            ListNode *pre = now->next;
            if (!pre)
                break;
            ListNode *tmp = pre->next;
            pre->next = now;
            now->next = tmp;
            if (!newHead)
            {
                newHead = pre;
                newTail = now;
            }
            else
            {
                newTail->next = pre;
                newTail = now;
            }
            
            now = tmp;
        }
        return newHead==nullptr?head:newHead;
    }
};