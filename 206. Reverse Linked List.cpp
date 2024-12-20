//https://leetcode.com/problems/reverse-linked-list/submissions/
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
#include<iostream>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *now = head, *newHead=nullptr;
        while (now)
        {
            ListNode *pre = now->next;
            now->next = newHead;
            newHead = now;
            now = pre;
        }
        return newHead;
    }
};