//https://leetcode.com/problems/climbing-stairs/
//f(n) = f(n-1)+f(n-2)
class Solution {
public:
    int climbStairs(int n) 
    {
        if (n<3)
            return n;
        
        //1个台阶有1种爬法；2个台阶2种; 之后每次相当于n-1个台阶向上爬1阶或者n-2个台阶向上爬2阶
        int fn1=1,fn=2;
        for (int i=3;i<=n;i++)
        {
            int temp = fn;
            fn = fn1+fn;
            fn1 = temp;
        }
        return fn;
    }
};