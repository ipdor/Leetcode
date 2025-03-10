//https://leetcode.com/problems/combinations/
class Solution {
public:
    vector<vector<int>> ans; //可以把ans和k也作为引用参数传入backtracing
    int k;
    void backtracing(int start, int n, vector<int> &bucket)
    {
        if(bucket.size()>=k)
        {
            ans.push_back(bucket);
            return;
        }
        //优化剪枝。还需选k-size个必须<=剩余可选n-i+1个
        for(int i = start; i<=n-k+bucket.size()+1; i++)
        {
            bucket.push_back(i);
            backtracing(i+1, n, bucket);
            bucket.pop_back();
        } 
    }
    vector<vector<int>> combine(int n, int k) 
    {
        this->k = k;
        vector<int> bucket;
        backtracing(1,n,bucket);
        return ans;
    }
};