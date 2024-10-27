//https://leetcode.com/problems/linked-list-cycle-ii/description/
//参考：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                ListNode *ptr = head;
                //2(x+y) = x+n(y+z)+y, x=(n-1)(y+z)+z
                //如果进入入口的距离短，那么不需要转一圈，n=1；否则slow多转几圈n>1
                while(ptr!=slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
            
        }
        return nullptr;
    }
};