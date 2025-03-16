//https://leetcode.com/problems/wiggle-subsequence/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.md
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return 1;
        //最后一定是一个峰值，从0到n-1遍历
        int prediff=0, postdiff = nums[1] - nums[0], cnt=1;
        for (size_t i = 0; i < nums.size()-1; i++)
        {
            postdiff = nums[i+1]-nums[i];
            if ((prediff<=0 && postdiff>0) || (prediff>=0 && postdiff<0))
            {
                cnt++;
                prediff = postdiff;
            }
        }
        return cnt; 
    }
};