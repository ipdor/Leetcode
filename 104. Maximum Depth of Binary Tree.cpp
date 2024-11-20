//104. Maximum Depth of Binary Tree
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
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level=0;
        while(!que.empty())
        {
            level++;
            int size = que.size();
            //每次处理一层的节点
            for(int i = 0;i<size; i++)
            {
                root = que.front(); que.pop();
                if(root->left) que.push(root->left);
                if(root->right) que.push(root->right);
            }
        }
        return level;
    }
};
/*
//递归法
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        else if(!root->left && !root->right)
            return 1;
        int leftDepth = maxDepth(root->left), rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth); 
    }
};
*/