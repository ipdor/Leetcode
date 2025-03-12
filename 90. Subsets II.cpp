//https://leetcode.com/problems/subsets-ii/
//默认把重复的数字当成不同的数字，这样可以使用重复的独立数字。
//但是重复数字只能处理一次，后期直接跳过。因为[2,3]和[3,2]不一样，但2换为3后[2,2]和[2,2]一样,避免组合相同
class Solution {
public:
    void backtrace(vector<int>& nums, int ind, vector<int>& ds, vector<vector<int>>& ans)
    {
        for (size_t i = ind; i < nums.size(); i++)
        {
            if (i>ind && nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            ans.push_back(ds);
            if(i+1<nums.size())
                backtrace(nums, i+1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> ds;
        vector<vector<int>> ans;
        ans.push_back(ds);
        sort(nums.begin(), nums.end());
        backtrace(nums, 0, ds, ans);
        return ans;
    }
};