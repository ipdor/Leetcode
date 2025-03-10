//https://leetcode.combination/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> digs;
    void traceback(string &digits, int ind, string &combination, vector<string>& ans)
    {
        if (digits.size()<= ind)
        {
            if(combination.size()>0)
                ans.push_back(combination);
            //cout<< "add: "<< combination;
            return;
        }
        string s = digs[digits[ind]-'0'];
        for (size_t i = 0; i < s.size(); i++)
        {
            combination.push_back(s[i]);
            traceback(digits, ind+1, combination, ans);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        string s[] = {"" ,"" ,"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        digs = vector<string>(s,s+10); 
        vector<string> ans;
        string combination;
        traceback(digits, 0, combination, ans);
        return ans;
    }
};