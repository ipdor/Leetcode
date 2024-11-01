//https://leetcode.com/problems/reverse-string-ii/description/
/*每次i+=2k，内部逆转最多k个字符。这样时间复杂度同样也是O(n)
外部循环O(n/2k), 内部每次执行的逆转函数复杂度O(k)，reverseStr总体复杂度O(n/2k * k) = O(n)
https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md
*/
class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int i = 0, tag = 0;
        for (; i < s.size(); i++)
        {
            int pos =i%(2*k), swapind = k-1-pos+i-pos;
            if(pos<(k/2) && swapind<s.size())
            {
                char tmp = s[i];
                s[i] = s[swapind];
                s[swapind] = tmp;
            }
            //逆转最后不足k个字符
            if (pos==0 && i+k>s.size())
            {
                int left = i, right = s.size()-1;
                while(left<right)
                {
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
                break;
            }
        }
        return s;
    }
};
