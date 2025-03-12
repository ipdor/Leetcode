//https://leetcode.com/problems/subsets/
class Solution {
public:
    void solve(vector<int>&nums, int ind, vector<int> &ds, vector<vector<int>>& ans)
    {
        for (size_t i = ind; i < nums.size(); i++)
        {
            ds.push_back(nums[i]);
            ans.push_back(ds);
            if (i+1<nums.size())
                solve(nums, i+1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> ds; 
        vector<vector<int>> ans;
        ans.push_back(ds);
        solve(nums, 0, ds, ans);
        return ans;
    }
};