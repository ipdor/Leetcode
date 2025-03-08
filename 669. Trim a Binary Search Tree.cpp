//https://leetcode.com/problems/trim-a-binary-search-tree/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0669.%E4%BF%AE%E5%89%AA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md
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
//迭代法就是两次分别处理左侧小值和右侧大值
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        while(true)
        {
            if(root->val >=low && root->val <=high)
                break;
            if(root->val<low)
                root = root->right;
            else if (root->val >high)
                root = root->left;
        }
        TreeNode* node= root;
        while (node->left && node->left->val < low)
        {
            node->left = node->left->right;
            node = node->left;
        }
        
        node = root;
        while (node->right && node->right->val > high)
        {
            node->right = node->right->left;
            node = node->right;
        }
        return root;
    }
};
/*
//递归法
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root==nullptr) return nullptr;
        if(root->val < low)  return trimBST(root->right,low, high);
        if(root->val > high)  return trimBST(root->left,low, high);
        root->left = trimBST(root->left,low, high);
        root->right = trimBST(root->right,low, high);
        return root;
    }
};
*/