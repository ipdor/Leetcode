//https://leetcode.com/problems/lemonade-change/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        vector<int> charge(21,0);
        for(int i = 0;i<bills.size();i++)
        {
            charge[bills[i]]++;
            if(bills[i] == 10)
            {
                if(charge[5]<=0)
                    return false;
                charge[5]--;
            }
            else if(bills[i] == 20) //5+10 or 5+5+5
            {
                if(charge[10]>=1)
                {
                    if (charge[5]<=0)
                        return false;
                    charge[5]--;
                    charge[10]--;
                }
                else
                {
                    if(charge[5]<3)
                        return false; 
                    else 
                        charge[5]-=3;
                }
            }
        }
        return true;
    }
};