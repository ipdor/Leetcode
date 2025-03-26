//https://leetcode.com/problems/binary-tree-cameras/description/
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
private:
    int cnt=0;
    //0：无覆盖；1：该节点是摄像头；2：有覆盖
    int camera(TreeNode* root)
    {
        if (!root)
            return 2;
        int left = camera(root->left), right = camera(root->right);
        if (left == 0 || right == 0)
        {
            cnt++;
            return 1;
        }
        //到这里说明左右子树都一定有覆盖
        if(left==1|| right==1)
            return 2;
        if(left==2|| right==2)
            return 0;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) 
    {
        if(camera(root)==0)
            cnt++;
        return cnt;
    }
};