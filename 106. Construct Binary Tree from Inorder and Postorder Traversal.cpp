//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.md
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
//可以交给另一个函数实现重建功能，调整参数减少时间空间开销
//TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size()==1 && postorder.size()==1)
        {
            return new TreeNode(inorder[0]);
        }
        int rootVal = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(rootVal);
        auto iter = find(inorder.begin(), inorder.end(), rootVal);
        int leftLen = iter-inorder.begin();
        if(leftLen)
        {
            vector<int> lin(inorder.begin(), iter), lpost(postorder.begin(), postorder.begin()+leftLen);
            root->left = buildTree(lin, lpost);
        }
        if(inorder.size()-leftLen-1)
        {
            vector<int> rin(iter+1, inorder.end()), rpost(postorder.begin()+leftLen, postorder.end()-1);
            root->right = buildTree(rin, rpost);
        }
        return root;
    }
};