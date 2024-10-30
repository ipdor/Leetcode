//https://leetcode.com/problems/ransom-note/description/
/*一些同学可能想，用数组干啥，都用map完事了，
其实在本题的情况下，使用map的空间消耗要比数组大一些的，
因为map要维护红黑树或者哈希表，而且还要做哈希函数，是费时的！
数据量大的话就能体现出来差别了。 所以数组更加简单直接有效！*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> alpha(26,0);
        for (auto al:magazine)
        {
            alpha[al-'a']++;
        }
        
        for (auto al:ransomNote)
        {
            int diff = al-'a';
            alpha[diff]--;
            if (alpha[diff]<0)
            {
                return false;
            }
        }
        return true;
    }
};