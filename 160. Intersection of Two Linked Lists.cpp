//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *nodeA = headA, *nodeB = headB;
        int lenA = 0, lenB = 0;
        //1. 各遍历一遍，获得个数
        while (nodeA)
        {
            nodeA = nodeA->next;
            lenA++;
        }
        while (nodeB)
        {
            nodeB = nodeB->next;
            lenB++;
        }
        
        //2. 长的先走个数差值 步之后同步遍历短的，如果有重叠就说明有交叉
        int diff = (lenA - lenB)>0?(lenA - lenB):(lenB - lenA);
        nodeA = headA;
        nodeB = headB;
        while (nodeA || nodeB)
        {
            if (nodeA==nodeB)
            {
                return nodeA;
            }
            
            if (lenA>=lenB || (lenB>lenA && diff<=0))
            {
                nodeA = nodeA->next;
            }
            if (lenB>=lenA || (lenA>lenB && diff<=0))
            {
                nodeB = nodeB->next;
            }
            diff--;
        }
        
        return nullptr;

    }
};