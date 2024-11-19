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