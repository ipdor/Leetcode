//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
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
    void insert(TreeNode* root, int val)
    {
        if(root->val < val)
        {
            if(root->right)
                return insert(root->right, val);
            else
            {
                root->right = new TreeNode(val);
            }

        }
        else if(root->val > val)
        {
            if(root->left)
                return insert(root->left, val);
            else
            {
                root->left = new TreeNode(val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==nullptr)
        {
            return new TreeNode(val);
        }
        insert(root, val);
        return root;
    }
};