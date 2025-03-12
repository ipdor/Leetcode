//https://leetcode.com/problems/palindrome-partitioning/
//和数字组合不同的是横向必须是分割而不是单个字符，如a,aa,aab。纵向也要到末尾
class Solution {
public:
    bool IsPalindrome(string &s)
    {
        for (size_t i = 0; i < s.size()/2; i++)
        {
            if (s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }
    void traceback(string &s, int ind, vector<string> &ds, vector<vector<string>>& ans)
    {
        if (ind>= s.size())
        {
            ans.push_back(ds);
            return;
        }
        string s1;
        for (size_t i = ind; i < s.size(); i++)
        {
            s1+=s[i];
            if(IsPalindrome(s1))
            {
                ds.push_back(s1);
                traceback(s, i+1, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string> ds;
        vector<vector<string>> ans;
        traceback(s, 0, ds, ans);
        return ans;
    }
};