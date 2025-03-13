//https://leetcode.com/problems/permutations/description/
//不能再每次ind+1，因为之后可能还会用到前面的数，如1,3,2。取而代之用used数组，每次加入没用过的数
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& used, vector<int>& ds, vector<vector<int>>& ans)
    {
        if (nums.size()==ds.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(used[i])
                continue;
            ds.push_back(nums[i]);
            used[i]=1;
            solve(nums, used, ds, ans);
            used[i]=0;
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> ds, used;
        for(int i =0;i<nums.size(); i++)
            used.push_back(0);
        vector<vector<int>> ans;
        solve(nums, used, ds, ans);
        return ans;
    }
};