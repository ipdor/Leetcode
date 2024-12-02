//https://leetcode.com/problems/minimum-absolute-difference-in-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int prev;
    int diff=INT_MAX;
    bool first=true;
    int getMinimumDifference(TreeNode* root) 
    {
        if(root->left) getMinimumDifference(root->left);
        if(first)
            first = false;
        else
        {
            if(abs(root->val-prev)< diff)
                diff = abs(root->val-prev);
        }
        prev = root->val;
        if(root->right) getMinimumDifference(root->right);
        return diff;
    }
};