//https://leetcode.com/problems/non-overlapping-intervals/
//为了去掉最少数量的区间应该按end排序，去掉中间的区间。画出三条线段的各种分离/重叠情况能帮助理解。
//不能按start最小排序，因为优先保留end最小的区间能确保后面留下更多位置,从而后面保留更多区间=删去更少区间。
//如[[1,100],[11,22],[1,11],[2,12]], start最小排序只保留[1,100], end最小排序能留下[1,11],[11,22]
bool comp(vector<int>& a, vector<int>&b) //该函数也可以写成Solution内部static函数
{
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0][1], ans=0;

        // for (size_t i = 0; i < intervals.size(); i++)
        //     cout<< intervals[i][0] <<"," << intervals[i][1] << " ";

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
                ans++;
            else
                end = intervals[i][1];
        }
        return ans;
    }
};