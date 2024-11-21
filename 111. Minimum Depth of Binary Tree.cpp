//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
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
//层序前序遍历，从上到下从左到右遍历各层的所有节点。如果发现一个叶子节点，直接返回此时level值
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level=0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for(int i = 0;i<size; i++)
            {
                root = que.front(); que.pop();
                if(!root->left && !root->right)
                    return level;
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
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        else if(root->right && root->left)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        else if(root->right)
            return minDepth(root->right)+1;
        else
            return minDepth(root->left)+1;
        
    }
};
*/