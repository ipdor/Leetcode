//https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.md
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
//用Map统计最简单最通用，但是没有利用好二叉搜索树的特性（中序遍历结果是非递减序列）
//注意最大出现次数=1的情况，此时遇到每个新数字都满足最大次数
class Solution {
public:
    int pre=-1e6;
    int cnt=0;
    int maxtimes=0;
    vector<int> res;
    void countFre(TreeNode* root)
    {
        if(root->left) countFre(root->left);
        if(pre==-1e6)
        {
            cnt++;
            res.push_back(root->val);
            maxtimes = cnt;
        }
        else
        {
            if(pre == root->val)
            {
                cnt++;
                if(cnt>maxtimes)
                {
                    res.clear();
                    res.push_back(root->val);
                    maxtimes = cnt;
                }
                else if(cnt==maxtimes)
                    res.push_back(root->val);
            }
            else
            {
                cnt=1;
                if(maxtimes==1)
                    res.push_back(root->val);
            }
        }
        // for(auto x:res)
        //     cout<< x <<" ";
        // cout<< root->val << " "<< maxtimes << endl;

        pre = root->val;
        if(root->right) countFre(root->right);
    }
    vector<int> findMode(TreeNode* root) 
    {
        res.clear();
        countFre(root);
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