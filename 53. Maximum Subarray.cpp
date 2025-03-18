//https://leetcode.com/problems/maximum-subarray/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.md
//贪心法关键在于任意前缀序列一定正数
//很容易知道为了取最大子序列和，首字符一定是正数。其实类似地，不只是单个字符，前几个字符如果和是负数也可以去除。
//如前3个元素[-2,1,-3]，不管从其中哪一个开始，他们的序列和都是负数，分别是-4,-2,-3，负数sum只会拖累总和。
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0, maxsum =0 ;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i]<0 || sum+nums[i]< 0)
                sum = 0;
            else
                sum+=nums[i];
            if (sum>maxsum)
                maxsum = sum;
        }
        return maxsum;
    }
};