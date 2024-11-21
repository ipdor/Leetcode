//https://leetcode.com/problems/count-complete-tree-nodes/
//复杂度O(logN * logN)
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0222.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0.md
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
    int getDepth(TreeNode* root, bool left)
    {
        if(!root)
            return 0;
        return getDepth(left?root->left:root->right, left)+1;
    }

    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int cnt=0;
        while(!que.empty())
        {
            root = que.front(); que.pop();
            int ld = getDepth(root, true), rd=getDepth(root, false);
            //cout << ld <<" " << rd<<endl;
            if(ld==rd)
            {
                cnt+=pow(2,ld)-1;   //(2 << leftDepth) 这样求2的次方更方便
                continue;
            }
            cnt++;
            if(root->left) que.push(root->left);
            if(root->right) que.push(root->right);
        }
        
        return cnt;
    }
};