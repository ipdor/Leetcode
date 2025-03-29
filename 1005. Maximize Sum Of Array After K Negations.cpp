//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/1005.K%E6%AC%A1%E5%8F%96%E5%8F%8D%E5%90%8E%E6%9C%80%E5%A4%A7%E5%8C%96%E7%9A%84%E6%95%B0%E7%BB%84%E5%92%8C.md
//关键在于先负转正，再正转负。并且按照绝对值考虑而不是大小。
//2025.3.18创建文件并第一次AC，看了题解
//2025.3.29第二次AC
class Solution {
private:
    static bool comp(const int a, const int b)
    {
        return abs(a)<abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        //1.有负数转正数，尽量把所有负数转正，按绝对值从大到小转
        //2.全是正数且k是偶数则直接返回
        //3.全是正数且k是奇数，那么把绝对值最小的正数转负，返回
        sort(nums.begin(), nums.end(), comp);
        for (int i = nums.size()-1; i >=0 && k>0 ; i--)
        {
            if (nums[i]<0)
            {
                nums[i]*=-1;
                k--;
            }
        }
        if (k%2==0)
            return accumulate(nums.begin(), nums.end(), 0);
        nums[0]*=-1;
        return accumulate(nums.begin(), nums.end(), 0);
    }
};