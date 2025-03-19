//https://leetcode.com/problems/monotone-increasing-digits/
class Solution {
public:
    int monotoneIncreasingDigits(int n) 
    {
        //从左往右找第一个不符合的digit
        string num = to_string(n);
        int highd = num[0], i = 0;
        for (i = 0; i < num.size()-1; i++)
        {
            if (num[i] > num[i+1])
                break;
        }
        if(i==num.size()-1)
            return n;
        //从右往左改digits, 数字XYZ中给定XY，Z合法范围是[Y,9]
        //此时数字不合法，需要从Y修改
        for(; i>0 ;i --)
            //num[i]<=num[i-1]时，合法范围内第i位/Y不能再改小了，需要从i-1位/X开始改
            if (num[i]>num[i-1])
                break;
        num[i++]--;
        for (; i < num.size(); i++)
            num[i]= '9';
        return stoi(num);
    }
};