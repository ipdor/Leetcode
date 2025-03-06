//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//关键在于回溯法的使用
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)
            return nullptr;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //root is the lowest common ancestor
        //root is q/p and the another is its descendants; root is neither p nor q but it's the LCA
        if (root->val == p->val || root->val == q->val || left && right)
            return root;
        if(left)
            return left;
        else if (right)
            return right;
        else
            return nullptr;
    }
};