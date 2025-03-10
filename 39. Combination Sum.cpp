//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void traceback(vector<int>& candidates, int target, int startInd, vector<int> &comba, vector<vector<int>> &ans)
    {
        if (0==target)
        {
            ans.push_back(comba);
            return;
        }
        //2. 从startInd开始循环，并且递归必须传入i作为下次startInd
        for (size_t i = startInd; i < candidates.size(); i++)
        {
            if (target - candidates[i]<0)
                continue;
            comba.push_back(candidates[i]);
            traceback(candidates, target - candidates[i], i, comba, ans);
            comba.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>comba;
        vector<vector<int>> ans;
        traceback(candidates, target, 0, comba, ans);
        //1.手动去重
        //去重，排序后unique把不重复元素放到前面，再删除重复元素
        // for (auto &x:ans)
        //     sort(x.begin(), x.end());
        // sort(ans.begin(), ans.end());
        // //unique返回指向第一个重复元素的迭代器it，可以通过distance(ans.begin(), it);进行验证
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};