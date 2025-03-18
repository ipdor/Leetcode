//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1005.K%E6%AC%A1%E5%8F%96%E5%8F%8D%E5%90%8E%E6%9C%80%E5%A4%A7%E5%8C%96%E7%9A%84%E6%95%B0%E7%BB%84%E5%92%8C.md
//关键在于先负转正，再正转负。并且按照绝对值考虑而不是大小。
bool compare(const int &a, const int &b)
{
    return abs(a) > abs(b);
}
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        //绝对值从小到大
        sort(nums.begin(), nums.end(), compare);
        int sum = 0;
        
        //把负数转正，从绝对值最大的开始转
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(k>0 && nums[i]<0)
            {
                nums[i] *= -1;
                k--;
            }
            sum+= nums[i];
        }
        bool even = (k%2==0);
        if(k%2==0)
            return sum;
        //正数转负，从绝对值最小的开始转，只转一次
        sum = 0;
        for (int i = nums.size()-1; i>=0; i--)
        {
            if(k>0 && !even)
            {
                nums[i] *= -1;
                even = true;
            }
            sum+=nums[i];
        }
        return sum;
    }
};