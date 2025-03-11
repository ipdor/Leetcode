//https://leetcode.com/problems/combination-sum-ii/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.md
//不能去重，会内存超出限制。因此必须在计算过程中去除重复组合。
//关键是利用排序，对同一层级元素进行去重，但是纵向一条路径上不去重，需要ind+1（不能多选同一个元素）
class Solution {
public:
    void traceback(vector<int>& can, int target, int startInd, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        if (startInd>=can.size())
            return;
        for (size_t i = startInd; i < can.size(); i++)
        {
            if (target<can[i] || (i>startInd && can[i]==can[i-1]))
                continue;
            ds.push_back(can[i]);
            traceback(can, target-can[i], i+1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        traceback(candidates, target, 0, ds, ans);
        
        return ans;
    }
};