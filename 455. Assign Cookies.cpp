//https://leetcode.com/problems/assign-cookies/
//"贪婪"的点在于大饼干可以同时匹配大g和小g，但是如果匹配小g，小饼干可能无法匹配就浪费了。
//每个饼干匹配g<=s的最大g，这样实现全局最优
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int lastone = g.size(), cnt = 0;
        for (int i = s.size()-1; i >=0 ; i--)
        {
            if(i!= s.size()-1 && cnt==0)
                break;
            for (int j = lastone-1; j >=0 ; j--)
            {
                if (s[i] >= g[j])
                {
                    cnt++;
                    lastone = j;
                    break;
                }
            }
        }
        return cnt;
    }
};