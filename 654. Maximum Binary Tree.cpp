//https://leetcode.com/problems/maximum-binary-tree/
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
    //左闭右开
    TreeNode* buildTree(vector<int>& nums, int beg, int end)
    {
        if(end<=beg)
            return nullptr;
        int indMax=-1, max=-10e6;
        for(int i =beg;i<end; i++)
        {
            //cout<<nums[i] << " ";
            if(nums[i]>max)
            {
                indMax=i;
                max=nums[i];
            }
        }
        TreeNode* root = new TreeNode(max);
        //注意后面边界起始和结束不再是0和nums.size()
        if(indMax-1 >=beg)
            root->left = buildTree(nums, beg, indMax);

        if(end-1 >=indMax+1)
            root->right = buildTree(nums, indMax+1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return buildTree(nums, 0, nums.size());
    }
};
/*
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int indMax=-1, max=-10e6;
        for(int i =0;i<nums.size(); i++)
        {
            if(nums[i]>max)
            {
                indMax=i;
                max=nums[i];
            }
        }
        TreeNode* root = new TreeNode(max);
        if(indMax-1 >=0 )
        {
            vector<int> left(nums.begin(), nums.begin()+indMax);
            root->left = constructMaximumBinaryTree(left);
        }
        if(nums.size()-1 >= indMax+1)
        {
            vector<int> right(nums.begin()+indMax+1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};
*/