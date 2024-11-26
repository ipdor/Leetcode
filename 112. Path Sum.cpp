//https://leetcode.com/problems/path-sum/description/
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
//递归法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;
        targetSum-=root->val;
        if(!root->left && !root->right)
        {
            return targetSum==0;
        }
        return hasPathSum(root->left, targetSum)||hasPathSum(root->right, targetSum);
    }
};
/*
//迭代法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;
        //也可以一个栈保存2个值stack<pair<TreeNode*, int>> st;
        stack<TreeNode*> st;
        stack<int> stVal;
        st.push(root);
        stVal.push(targetSum);
        while(!st.empty())
        {
            root = st.top(); st.pop();
            int val = stVal.top(); stVal.pop();
            val-=root->val;
            if(!root->left && !root->right && val==0)
                return true;
            if(root->left)
            {
                st.push(root->left);
                stVal.push(val);
            }
            if(root->right)
            {
                st.push(root->right);
                stVal.push(val);
            }
        }
        return false;
    }
};
*/