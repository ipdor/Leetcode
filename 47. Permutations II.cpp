//https://leetcode.com/problems/permutations-ii/description/
//类似组合问题，同一层级不能用两个同样的元素，因此需要排序+从第二个重复元素开始跳过重复元素。
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& used, vector<int>& ds, vector<vector<int>>& ans)
    {
        if (nums.size() == ds.size())
        {
            ans.push_back(ds);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            //第二个跳过的条件要理清楚，和组合不完全一样。
            if(used[i] || (i>0 && nums[i-1]==nums[i] && used[i-1]))
                continue;
            ds.push_back(nums[i]);
            used[i] = 1;
            solve(nums, used, ds, ans);
            ds.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<int> ds, used;
        vector<vector<int>> ans;
        for (size_t i = 0; i < nums.size(); i++)
            used.push_back(0);
        sort(nums.begin(), nums.end());
        solve(nums, used, ds, ans);
        return ans;
    }
};