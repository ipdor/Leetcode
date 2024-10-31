//https://leetcode.com/problems/4sum/
/*
本题比15 三数之和更难一点，需要注意几个点：
1. 由于要求和是target未必是0，要注意i和j结束循环时的条件要包括nump[i/j]>0,若小于0不能确定找不到解。
    否则无法通过如[-2,-1,0,0] target=-3;
2. j结束循环要考虑目前两数之和nums[i]+nums[j]与target的比较，而不是只有nums[j];
3. 第二个循环从i+1开始，因此去重时要包括j>i+1，否则会去掉所有的nums[i]和nums[j]相对的数值，如[-1,-1,0,1];
4. 和target比较时需要转换为long，否则数值超过int范围.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]>=0&&nums[i] > target)
            {
                return res;
            }
            if (i>0 && nums[i-1]==nums[i])
            {
                continue;
            }
            
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[j]>=0&&nums[i]+nums[j] > target)
                {
                    break;
                }
                if (j>i+1 && nums[j-1]==nums[j])
                {
                    continue;
                }
                int left = j+1;
                int right = nums.size()-1;
                while (left<right) 
                {
                    if ((long)nums[i]+nums[j]+nums[left]+nums[right] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[i]+nums[j]+nums[left]+nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int> pair{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(pair);
                        while (left<right && nums[left+1] == nums[left])
                            left++;
                        while (left<right && nums[right-1] == nums[right])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
            
        }
        return res;
        
    }
};