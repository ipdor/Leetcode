//https://leetcode.com/problems/happy-number/description/
class Solution {
    int getNew(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) 
    {
        unordered_set<int> set;
        while(n!=1)
        {
            if (set.find(n) == set.end())
            {
                set.insert(n);
            }
            else
                return false;
            n = getNew(n);
        }
        return true;
    }
};