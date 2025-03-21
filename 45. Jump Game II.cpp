//https://leetcode.com/problems/jump-game-ii/
//贪心在于每一步都走最远距离,每次找到第i步最远的距离。每次超出范围步数+1。如nums[0]=2，那么第1步最远到达i=2
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()==1) return 0;
        int maxd = nums[0], nextMaxd=0, ans = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (i>maxd)
            {
                maxd= nextMaxd;
                nextMaxd = 0;
                ans++;
            }
            int d = i+nums[i];
            if (d>nextMaxd)
                nextMaxd = d;
        }
        return ans;
    }
};