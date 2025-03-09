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
        for(int i = start; i<=n; i++)
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