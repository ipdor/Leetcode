//https://leetcode.com/problems/non-decreasing-subsequences/
//可以通过哈希表替代unordered_set来进一步提高效率。
//也可以用dfs算法。每个元素最多有填和不填两种情况。填时只能有非递减序元素，
//不填时注意避开相同元素（比如[4,6,7,7],不填i=2和不填i=3时集合相同4,6,_,7=4,6,7,_），可以让last=当前元素时本元素不能不填，避免出现4,6,7,_
class Solution {
public:
    void backtrace(vector<int>& nums, int ind, vector<int>& ds, vector<vector<int>>& ans)
    {
        unordered_set<int> used;
        for (size_t i = ind; i < nums.size(); i++)
        {
            if ((ds.size()>0 && ds.back() > nums[i]) || (used.find(nums[i])!= used.end()))
                continue;
            used.insert(nums[i]);
            
            ds.push_back(nums[i]);
            if(ds.size()>1)
                ans.push_back(ds);
            if(i+1<nums.size())
                backtrace(nums, i+1, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<int> ds;
        vector<vector<int>> ans;
        backtrace(nums, 0, ds, ans);
        return ans;
    }
};