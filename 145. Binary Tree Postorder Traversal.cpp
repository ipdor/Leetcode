//https://leetcode.com/problems/binary-tree-postorder-traversal/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.md
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
//迭代通用方案
//每次遍历节点时，除了左右节点把中间节点也重新插入，但同时放置NULL节点进行标记
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        std::stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            if(root)
            {
                st.push(root);
                st.push(nullptr);
                if(root->right) st.push(root->right);
                if(root->left) st.push(root->left);
            }
            else
            {
                //说明此时栈顶元素是中间节点
                TreeNode* node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};
/*
//迭代方案
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        std::stack<TreeNode*> st;
        if (root) st.push(root);
        
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            res.push_back(root->val);
            if(root->left) st.push(root->left);
            if(root->right) st.push(root->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//递归通用方案
class Solution {
public:
    vector<int> res;
    void traverse(TreeNode* root)
    {
        if(root)
        {
            
            if(root->left) traverse(root->left);
            if(root->right) traverse(root->right);
            res.push_back(root->val);
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        traverse(root);
        return res;
    }
};
*/