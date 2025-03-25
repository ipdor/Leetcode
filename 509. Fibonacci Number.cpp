//https://leetcode.com/problems/fibonacci-number/
class Solution {
public:
    int fib(int n) 
    {
        if(n<2)
            return n;
        int fn1 = 0, fn=1,k=2;
        while (k<=n)
        {
            int fk = fn1+fn;
            fn1 = fn;
            fn = fk;
            k++;
        }
        return fn;
    }
};