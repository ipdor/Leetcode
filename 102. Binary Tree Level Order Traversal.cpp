//https://leetcode.com/problems/binary-tree-level-order-traversal/
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
//先把root放入，之后每次把queue里的n个元素遍历完时就遍历完了一层
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        std::queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root) que.push(root);
        else return res;
        while(!que.empty())
        {
            int size = que.size(); //这里保存大小，否则que.size()是动态变化的
            vector<int> level;
            for(int i = 0; i< size; i++)
            {
                root = que.front();
                que.pop();
                level.push_back(root->val);
                if(root->left) que.push(root->left);
                if(root->right) que.push(root->right);
            }
            res.push_back(level);
        }
        return res;
    }
};