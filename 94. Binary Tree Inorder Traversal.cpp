//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root)
        {
            if(root->left)
            {
                vector<int> a = inorderTraversal(root->left);
                res.insert(res.end(), a.begin(), a.end());
            }
            res.push_back(root->val);
            if(root->right)
            {
                vector<int> a = inorderTraversal(root->right);
                res.insert(res.end(), a.begin(), a.end());
            }
        }
        return res;
    }
};