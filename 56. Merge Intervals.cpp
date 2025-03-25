//https://leetcode.com/problems/merge-intervals/
//和452.用最少数量的箭引爆气球，435.无重叠区间非常类似
class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), comp);
        int beg=intervals[0][0], end=intervals[0][1];
        vector<vector<int>> ans;
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end && intervals[i][0] >=beg)
                end = max(intervals[i][1], end);
            else
            {
                ans.push_back(vector<int>({beg, end}));
                beg=intervals[i][0], end=intervals[i][1];
            }
        }
        ans.push_back(vector<int>({beg, end}));
        return ans;
    }
};