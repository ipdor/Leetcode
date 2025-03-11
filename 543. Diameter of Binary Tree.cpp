//https://leetcode.com/problems/diameter-of-binary-tree/?envType=problem-list-v2&envId=9oxrrsw3
//最长路径=max(全局最长路径，左子树高度+右子树高度),这里定义叶子节点高度=1
//全局变量保存目前最长路径，函数返回高度。如果最长路径在子树中，由于是自底向上计算， 处理父节点时最长路径已经保存到了maxd
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
    int maxd=0;
    int getHeight(TreeNode* root) 
    {
        if(!root)
            return 0;
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        maxd = max(leftH+rightH, maxd);
        return max(leftH,rightH)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        getHeight(root);
        return maxd;
    }
};
//最长路径=max(左子树最长路径，右子树最长路径，左子树高度+2+右子树高度)，其实可以化简
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) 
//     {
//         if (!root->left && !root->right)
//         {
//             root->val = 0;
//             return 0;
//         }
//         int leftd = 0, rightd = 0, maxl=0;
//         if(root->left)
//         {
//             leftd = diameterOfBinaryTree(root->left);
//         }
//         if(root->right)
//         {
//             rightd = diameterOfBinaryTree(root->right);
//         }
//         if(root->left && root->right)
//         {
//             root->val = root->left->val>root->right->val?root->left->val+1:root->right->val+1;
//             maxl = root->left->val + root->right->val +2;
//         }
//         else if(root->left)
//         {
//             root->val = root->left->val+1;
//             maxl = root->val;
//         }
//         else
//         {
//             root->val = root->right->val+1;
//             maxl = root->val;
//         }
//         int maxd = leftd>rightd?leftd:rightd;
        
//         return maxl > maxd? maxl: maxd;
//     }
// };