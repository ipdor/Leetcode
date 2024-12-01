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
//中序遍历，获得数组的递增/各数字递增说明是合格搜索树
//最笨的办法是每个节点从上到下遍历一次，判断是否左边小右边大
class Solution {
public:
    int pre = INT_MIN;
    bool first=true;
    bool inOrder(TreeNode* root)
    {
        if(root->left && inOrder(root->left) == false)
            return false;
        //cout<< root->val << " ";

        if(first)
            first=false;
        else 
        {
            if(root->val <= pre)
            return false;
        }
        pre = root->val;
        if(root->right && inOrder(root->right) == false)
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) 
    {
        return inOrder(root);
    }
};
/*
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &res)
    {
        if(root->left) inOrder(root->left, res);
        res.push_back(root->val);
        if(root->right) inOrder(root->right, res);
        return;
    }
    bool isValidBST(TreeNode* root) 
    {
        vector<int> res;
        inOrder(root, res);
        int pre=res[0];
        for(int i = 1; i<res.size(); i++)
        {
            int x = res[i];
            //cout<< x<< " ";
            if(x<=pre)
                return false;
            pre = x;
        }
        //cout <<endl;

        return true;
    }
};
*/