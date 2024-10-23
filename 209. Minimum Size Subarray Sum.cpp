//https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int minStep=1e7, beg = 0, sum=0;
        for (int j = 0; j< nums.size(); j++)
        {
            sum+=nums[j];
            //缩小beg来尝试找到最小step
            while(sum>=target)
            {
                int step = j-beg+1;
                if(minStep> step)minStep= step;
                sum-=nums[beg++];
            }
        }
        return minStep==1e7?0:minStep;
    }
};