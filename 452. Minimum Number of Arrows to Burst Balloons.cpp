//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//[[1,6],[2,8],[7,12],[10,16]]。第3个区间和第2第4个都可以重合，那么应该重合哪个？
//第4个。因为如果和中间重合，两边需要单独各1枝箭，总共3枝。因此，排序后从一端开始往另一端遍历
//1个区间只需要1枝箭；2个区间有两种情况需要判断：相交和分离；3个区间可以化简成2个区间，以此类推。
//也可以不保存重合区间，只保存右边界。每次如果不重合那么更新i并cnt++
bool comp(vector<int>& a, vector<int>&b)
{
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), comp);
        int start = points[0][0], end = points[0][1], cnt=1; 
        for (size_t i = 1; i < points.size(); i++)
        {
            //cout<< points[i][0] << "," << points[i][1] << endl;
            if (points[i][0]> end)
            {
                cnt++;
                start = points[i][0]; 
                end = points[i][1];
                continue;
            }
            start = points[i][0]; //由于sort是根据Xstart递增排序，points[i][0]一定不小于start
            end = end< points[i][1]? end: points[i][1];
            //cout<< "ith: "  << start << "," << end << endl;
        }
        return cnt;
    }
};