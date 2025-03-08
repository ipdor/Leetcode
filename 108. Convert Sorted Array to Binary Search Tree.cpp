//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    //每次插入一个节点，然后nums左侧作为左子树，右侧作为右子树
    TreeNode* buildBST(vector<int>& nums, int beg, int end, int thisInd)
    {
        if (end<=beg || thisInd<beg || thisInd>=end)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(nums[thisInd]);
        node->left =  buildBST(nums, beg, thisInd, (beg+thisInd)/2);
        node->right = buildBST(nums, thisInd+1, end, (end+1+thisInd)/2);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return buildBST(nums, 0, nums.size(), nums.size()/2);
    }
};