//https://leetcode.com/problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 1;
        for (int i = digits.size()-1; i >=0; i--)
        {
            digits[i]++;
            carry--;
            if (digits[i]==10)
            {
                carry=1;
                digits[i] = 0;
                
            }
            if (!carry)
                break;
        }
        if (carry)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};