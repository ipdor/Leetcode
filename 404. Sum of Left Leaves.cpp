//https://leetcode.com/problems/sum-of-left-leaves/description/
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
//迭代法
//迭代也可以使用深度遍历，使用栈实现
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        queue<TreeNode*> que;
        que.push(root);
        int sum=0;
        while(!que.empty())
        {
            root = que.front(); que.pop();
            if(root->left)
            {
                if(!root->left->left && !root->left->right)
                    sum+= root->left->val;
                else
                    que.push(root->left);
            }
            if(root->right) que.push(root->right);
        }
        return sum;
    }
};
/*
//递归法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        if(root->left)
        {
            if(!root->left->left && !root->left->right)
                return root->left->val + sumOfLeftLeaves(root->right);
            else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
        else
        {
            return sumOfLeftLeaves(root->right);
        }
        return 0;
    }
};
*/