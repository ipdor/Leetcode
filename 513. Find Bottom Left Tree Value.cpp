//https://leetcode.com/problems/find-bottom-left-tree-value/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0513.%E6%89%BE%E6%A0%91%E5%B7%A6%E4%B8%8B%E8%A7%92%E7%9A%84%E5%80%BC.md
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
    int maxDepth=-999;
    int value;
    void DFS(TreeNode* root, int depth)
    {
        if(!root->left && !root->right && depth>maxDepth)
        {
            value = root->val;
            maxDepth = depth;
        }
        if(root->left) DFS(root->left,depth+1);   // 隐藏着回溯
        if(root->right) DFS(root->right,depth+1); // 隐藏着回溯
    }
    int findBottomLeftValue(TreeNode* root) 
    {
        DFS(root,1);
        return value;
    }
};
/*
//层序迭代法
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> que;
        que.push(root);
        int value=0;
        while(!que.empty())
        {
            
            int size = que.size();
            for (int i=0; i< size; i++)
            {
                root = que.front(); que.pop();
                value = root->val;
                if(root->right) que.push(root->right);
                if(root->left) que.push(root->left);
            }

        }

        return value;
    }
};
*/