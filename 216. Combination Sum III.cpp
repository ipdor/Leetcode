//https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    vector<int> nums;
    void backtrace(int k, int n, int startInd, vector<int> &ds, vector<vector<int>> &ans)
    {
        if(k<=0)
        {
            if(n==0)
                ans.push_back(ds);
            return;
        }
        for (size_t i = startInd; i <  nums.size(); i++)
        {
            if (nums[i]>n)
                return;
            ds.push_back(nums[i]);
            backtrace(k-1, n-nums[i], i+1, ds, ans); //记住不是startInd+1，是i+1
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        for(int i=0;i<10;i++)
            nums.push_back(i);
        vector<int> ds;
        vector<vector<int>> ans;
        backtrace(k, n, 1, ds, ans);
        return ans;
    }
};