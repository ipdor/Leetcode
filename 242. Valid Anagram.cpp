//https://leetcode.com/problems/valid-anagram/description/
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.size()!= t.size())
        {
            return false;
        }
        int alphaCntS[26] = {0}, alphaCntT[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            alphaCntS[s[i] - 'a']++;
            alphaCntT[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (alphaCntS[i] != alphaCntT[i])
            {
                return false;
            }
        }
        return true;
    }
};