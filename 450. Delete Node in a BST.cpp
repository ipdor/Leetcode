//https://leetcode.com/problems/delete-node-in-a-bst/
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
    bool DFSSearch(TreeNode* root, int key)
    {
        if(!root)
            return false;
        if(key < root->val)
            return DFSSearch(root->left, key);
        else if(key > root->val)
            return DFSSearch(root->right, key);
        else return true;
    }
    TreeNode* Delete(TreeNode* root, int key) 
    {
        if(root->val == key)
        {
            TreeNode* node = root->right, *prev = root;
            if(!node)
                root = root->left;
            else
            {
                while(node->left)
                {
                    prev = node;
                    node = node->left;
                }
                root->val = node->val;
                //root->right=root右子树最左下节点的特殊情况
                if(prev==root)
                    root->right = node->right;
                else
                    prev->left = node->right;
                delete node;
            }
            return root;
        }
        else
        {
            if(root->left) root->left = Delete(root->left, key);
            if(root->right) root->right = Delete(root->right, key);
            return root;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        //1. 找到这个节点；找不到就直接返回，无需删除
        //2. 找到节点右子树最左侧节点，替代本节点值并删除改节点。找不到（没有右子树）就直接用左子树替代。
        bool find = DFSSearch(root, key);
        if(!find)
            return root;
        return Delete(root, key);
    }
};