//https://leetcode.com/problems/balanced-binary-tree/
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
    int getDepth(TreeNode* root)
    {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level=0;
        while(!que.empty())
        {
            int size=que.size();
            level++;
            for(int i =0;i<size;i++)
            {
                root = que.front(); que.pop();
                if(root->left) que.push(root->left);
                if(root->right) que.push(root->right);
            }
        }
        return level;
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;
        int ld = getDepth(root->left), rd = getDepth(root->right);
        //cout<<ld<< " "<<rd<<endl;
        if(abs(ld-rd)>1)
            return false;
        return  isBalanced(root->left)&& isBalanced(root->right);
        
        
    }
};