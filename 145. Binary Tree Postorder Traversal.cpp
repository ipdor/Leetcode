//https://leetcode.com/problems/binary-tree-postorder-traversal/
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
            
            if(root->left) traverse(root->left);
            if(root->right) traverse(root->right);
            res.push_back(root->val);
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        traverse(root);
        return res;
    }
};