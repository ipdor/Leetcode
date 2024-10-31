//https://leetcode.com/problems/3sum-closest/description/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int res = 1e9;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i+1, right = nums.size()-1;
            while(left<right)
            {
                int curNum = nums[i] + nums[left] + nums[right];
                if(abs(curNum - target) < abs(res - target))
                {
                    res = curNum;
                }

                if (curNum < target)
                {
                    left++;
                }
                else if (curNum > target)
                {
                    right--;
                }
                else
                {
                    return target;
                }
            }
        }
        return res;
        
    }
};