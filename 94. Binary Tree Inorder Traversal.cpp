//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        std::stack<TreeNode*> st;
        if(root) st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            if(root)
            {
                //右中左
                if(root->right) st.push(root->right);
                st.push(root);
                st.push(nullptr);
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
//1. 有左节点就一直访问左节点，同时保存访问过的节点
//2. 访问到空节点时返回上个节点，此时该节点左侧已全部遍历，可以输出
//3. 类似1不断遍历该节点右侧
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                //访问到空节点时，根据栈的记录返回上个节点
                //因为push前有判断if，所以节点都不为空
                //此时访问左到头，可以取父节点值
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                //继续不断访问右边
                cur = cur->right;
            }
        }
        return res;
    }
};
//递归通用方案
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root)
        {
            if(root->left)
            {
                vector<int> a = inorderTraversal(root->left);
                res.insert(res.end(), a.begin(), a.end());
            }
            res.push_back(root->val);
            if(root->right)
            {
                vector<int> a = inorderTraversal(root->right);
                res.insert(res.end(), a.begin(), a.end());
            }
        }
        return res;
    }
};
*/