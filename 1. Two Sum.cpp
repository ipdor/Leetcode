//https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> umap;
        for(int i = 0;i <nums.size(); i++)
        {
            auto iter= umap.find((target-nums[i]));
            if (iter!= umap.end())
            {
                return vector<int>{iter->second,i};
            }
            else
                umap.insert({nums[i],i});
        }
        
        return vector<int>(0,1);
    }
};


/*
本题其实有四个重点：
    为什么会想到用哈希表
        需要多次查找，如果不用哈希表那么就是2个循环暴力遍历，O(n^2)时间复杂度
    哈希表为什么用map
        - 数组: 数字范围+-10^9，范围太大而且可能很稀疏
        - set: 除了数字还需要获取对应下标
    本题map是用来存什么的
        遍历nums[i]时，从map中查找需要的target-nums[i]
    map中的key和value用来存什么的
        数字和对应下标
*/