//https://leetcode.com/problems/binary-tree-paths/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.md
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
//迭代法没想到,是不是带参数的迭代需要用额外栈来进行模拟？
//每次遍历结果不是把节点值放入vector，而是把节点路径（包括节点值）放入stack中和遍历堆栈共同维护
//差别1.不是vector 2.不是保存节点值而是访问到该节点的完全路径
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        //vector<int> path;
        vector<string> res;
        stack<TreeNode*> st;
        stack<string> stpath;
        st.push(root);
        stpath.push(to_string(root->val));
        while(!st.empty())
        {
            root = st.top(); st.pop();
            string str = stpath.top(); stpath.pop();
            
            if(!root->left && !root->right)
            {
                res.push_back(str);
            }
            if(root->right)
            {
                st.push(root->right);
                stpath.push(str+"->"+to_string(root->right->val));
            }
            if(root->left)
            {
                st.push(root->left);
                stpath.push(str+"->"+to_string(root->left->val));
            }
        }
        return res;
    }
};
/*
class Solution {
public:
    //1.确定函数参数和返回值
    //2.确定递归返回条件
    //3.确定单层递归逻辑
    //4.回溯和递归是一一对应的，有一个递归，就要有一个回溯
    void traversal(TreeNode* root, vector<int> &path, vector<string> &res)
    {
        path.push_back(root->val);
        // cout<< root->val <<endl;
        if(!root->left && !root->right)
        {
            string str;
            for(int i = 0;i<path.size(); i++)
            {
                if(i==0)
                    str+=to_string(path[i]);
                else
                    str+="->"+to_string(path[i]);
            }
            res.push_back(str);
            return;
        }
        if(root->left)
        {
            traversal(root->left, path, res);
            //还有种方法是参数path改为string类型，并且复制传递，这样不用回溯
            path.pop_back();
        }
        if(root->right)
        {
            traversal(root->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<int> path;
        vector<string> res;
        traversal(root, path, res);
        return res;
    }
};
*/