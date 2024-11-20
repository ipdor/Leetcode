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
//同样可以使用栈成对放入两个镜像子树
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty())
        {
            TreeNode* lTree = que.front(); que.pop();
            TreeNode* rTree = que.front(); que.pop();

            if(!lTree && !rTree)
                continue;
            // 左右一个节点为空，或者都不为空但数值不相同，返回false
            else if(!rTree || !lTree|| (lTree->val != rTree->val))
                return false;
            
            que.push(lTree->left);
            que.push(rTree->right);
            que.push(lTree->right);
            que.push(rTree->left);
        }
        return true;
    }
};
/*
//递归法
class Solution 
{
public:
    bool DFS(TreeNode* lTree, TreeNode* rTree)
    {
        if(!lTree && !rTree)
            return true;
        else if((lTree && !rTree) || (!lTree && rTree))
            return false;
        return lTree->val==rTree->val && DFS(lTree->right, rTree->left) && DFS(lTree->left, rTree->right);
    }
    bool isSymmetric(TreeNode* root) 
    {
        TreeNode* lTree= root->left, *rTree=root->right;
        return DFS(lTree, rTree);
    }
};
*/