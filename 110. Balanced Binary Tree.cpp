//https://leetcode.com/problems/balanced-binary-tree/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91.md
//高度是从叶子节点下往上计算，深度相反
//求深度可以从上到下去查 所以需要前序遍历（中左右）;而高度只能从下到上去查，所以只能后序遍历（左右中）
//一个高度平衡二叉树是指对二叉树中的每个节点来说，其两个子树的深度之差从不超过1。
//2024.11.23创建文件并第一次AC，看了题解
//2025.3.30第二次AC
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
//迭代法,求深度和判断都是递归
class Solution {
public:
    int getDepth(TreeNode* root) 
    {
        if(!root) return 0;
        stack<TreeNode*> st;
        st.push(root);
        int result=0, depth=0;
        while(!st.empty())
        {
            root = st.top(); st.pop();
            if(root)
            {
                st.push(root);
                st.push(nullptr);
                depth++;
                if(root->right) st.push(root->right);
                if(root->left) st.push(root->left);
            }
            else
            {
                root = st.top(); st.pop();
                depth--;
            }
            result = result>depth?result:depth;
        }
        return result;
    }

    bool isBalanced(TreeNode* root) 
    {
        if(!root) return true;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            root = st.top(); st.pop();
            if(abs(getDepth(root->left)-getDepth(root->right))>1)
                return false;
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return true;
        
    }
};
/*
//递归法
class Solution {
public:
    //后序遍历二叉树计算高度。如果是平衡树返回最大高度，否则返回-1
    int getH(TreeNode* root) 
    {
        if(!root) return 0;
        //左，右
        int lheight = getH(root->left), rheight = getH(root->right);

        if(lheight==-1 || rheight==-1|| abs(lheight-rheight)>1)
            return -1;
        //中
        return max(lheight,rheight)+1;
    }

    bool isBalanced(TreeNode* root) 
    {
        int height = getH(root);
        //cout<< height <<endl;
        return height>=0;
    }
};
//迭代求深度，递归判断。对每个节点求深度，但是重复计算很多次，和迭代法原理相同
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

//1.需要子树深度 2.需要返回是否是高度平衡二叉树.但是返回值只能有一个，要么定义不平衡时返回值为负，要么用参数传递
class Solution {
public:
    //balanced:1, inbalance:0
    bool getH(TreeNode* root, int & h)
    {
        if (!root) //如果不需要定义叶子节点高度为0，那么这里不要添加条件，否则lh和rh也要判断是否需要+1
        {
            h = 0;
            return 1;
        }
        int lh=0, rh = 0;
        bool ans  = getH(root->left, lh) && getH(root->right, rh);
        h= max(lh, rh)+1;
        return ans&&abs(lh-rh)<=1;
    }
    bool isBalanced(TreeNode* root) 
    {
        int height = 0;
        return getH(root, height);
    }
};
*/

