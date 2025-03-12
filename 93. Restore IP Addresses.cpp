//https://leetcode.com/problems/restore-ip-addresses/
class Solution {
public:
    inline bool IsValidSubNet(string &s)
    {
        if(s.size()==0 || s.size()>3 || (s.size()>1 && s[0]=='0'))
            return false;
        int subnet = stoi(s);
        return subnet>=0 && subnet<=255;
    }
    void solve(string& s, int ind, int level, string& ip, vector<string> &ans)
    {
        if(level==3)
        {
            string subnet(s.begin()+ind, s.end());
            if (IsValidSubNet(subnet))
            {
                ip+=subnet;
                ans.push_back(ip);
                return;
            }
            return;
        }
        string subnet;
        for (size_t i = ind; i <s.size()-3+level && i<s.size(); i++)
        {
            subnet+=s[i];
            if (IsValidSubNet(subnet))
            {
                string tmp = ip;
                ip+=subnet+".";
                solve(s, i+1, level+1, ip, ans);
                ip=tmp;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) 
    {
        string ip;
        vector<string> ans;
        solve(s, 0, 0, ip, ans);
        return ans;
    }
};