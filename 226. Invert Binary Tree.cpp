//https://leetcode.com/problems/invert-binary-tree/description/
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
//迭代遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            if(root)
            {
                st.push(root);
                st.push(nullptr);
                if(root->left)  st.push(root->left);
                if(root->right) st.push(root->right);
            }
            else
            {
                root = st.top();
                st.pop();
                swap(root->left,root->right);
            }
        }
        return root;
    }
};
/*
//递归遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root)
        {
            swap(root->left,root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
*/