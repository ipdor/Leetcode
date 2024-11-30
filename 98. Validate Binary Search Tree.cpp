//https://leetcode.com/problems/validate-binary-search-tree/description/
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
    //是否子树所有值小于/大于value
    bool judgeBST(TreeNode* root, int value, int greater)
    {
        if(!root)
            return true;
        //cout<< root->val <<" "<< value <<" "<< greater << endl;
        if((greater && root->val <= value) || (!greater && root->val >= value))
        {
            return false;
        }
        return judgeBST(root->left, value, greater) && judgeBST(root->right, value, greater);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return true;
        bool res=1;
        if(judgeBST(root->left, root->val, 0)==0 || judgeBST(root->right, root->val, 1)==0)
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};