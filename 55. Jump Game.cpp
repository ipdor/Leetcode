//https://leetcode.com/problems/jump-game/
//贪心在于每一步都走最远距离，实现全局最远。注意可到达（遍历）的点不超过最远距离
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maxd = 0;
        for (size_t i = 0; i < nums.size()&& i<=maxd; i++)
        {
            int d = i+nums[i];
            if (d>maxd)
                maxd = d;
            if (maxd>=nums.size()-1)
                return true;
        }
        return false;
    }
};