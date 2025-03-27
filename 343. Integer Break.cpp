//https://leetcode.com/problems/integer-break/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.md
//这里其实用了一个数学方法，从n=5开始，每次拆成m个3，如果剩下是4，则保留4，然后相乘
class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp={0,1,1,2,4,6,9};
        if (n<=6)
            return dp[n];
        int fn_1 = dp[6], fn_2 = dp[5], fn_3 = dp[4];
        for (int i=7; i<=n; i++)
        {
            int fn = max(fn_2*2, fn_3*3);
            fn_3 = fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn_1;
    }
};
