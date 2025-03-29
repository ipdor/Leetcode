//https://leetcode.com/problems/linked-list-cycle/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//2024.10.27创建文件并AC（非第一次），看了题解
//2025.3.29再次AC
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow = head, *fast=head;
        //因为fast走过的slow一点走过，因此只要判断fast有效的情况
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast)
                return true;
        }
        return false;
    }
};