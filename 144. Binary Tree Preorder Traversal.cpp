//https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
    vector<int> res;

    void traverse(TreeNode* root)
    {
        if(root)
        {
            res.push_back(root->val);
            if(root->left)preorderTraversal(root->left);
            if(root->right) preorderTraversal(root->right);
        }
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        traverse(root);
        return res;
    }
};