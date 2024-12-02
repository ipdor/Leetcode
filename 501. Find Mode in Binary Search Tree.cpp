//https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
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
    vector<int> findMode(TreeNode* root) 
    {
        add2map(root);
        vector<int> res;
        
        return res;
    }
};
/*
class Solution {
public:
    unordered_map<int,int> m;
    void add2map(TreeNode* root)
    {
        if(root->left) add2map(root->left);
        if(m.find(root->val) != m.end())
            m[root->val]++;
        else
            m[root->val]=1;
        if(root->right) add2map(root->right);
    }
    vector<int> findMode(TreeNode* root) 
    {
        add2map(root);
        vector<int> res;
        int mostTimes=0;
        for(auto it=m.begin();it!=m.end(); it++)
        {
            //cout<< it->first << ":" << it->second <<endl;
            if(it->second > mostTimes)
                mostTimes = it->second;
        }
        for(auto it=m.begin();it!=m.end(); it++)
        {
            if(it->second ==mostTimes)
                res.push_back(it->first);
        }
        return res;
    }
};*/