//https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) 
    {
        //右中左遍历，每次sum+=节点值，节点值=sum
        if(!root) return nullptr;
        if(root->right) convertBST(root->right);
        sum+= root->val;
        root->val = sum;
        if(root->left) convertBST(root->left);
        return root;
    }
};