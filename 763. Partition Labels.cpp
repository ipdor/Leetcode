//https://leetcode.com/problems/partition-labels/
//统计每个字符出现的最后位置，当最后位置和当前位置相等时可以分割。
//用哈希表存储结果速度更快
class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> alphabet(26,0), ans;
        for (size_t i = 0; i < s.size(); i++)
            alphabet[s[i]-'a'] = i;
        int firstInd=0, lastInd = 0; //这段字符串的起始和结束ind
        for (int i = 0; i < s.size(); i++)
        {
            int find = alphabet[s[i]-'a'];
            if (find > lastInd)
                lastInd = find;
            if (i== lastInd)
            {
                ans.push_back(lastInd-firstInd+1);
                firstInd = i+1;
            }
        }
        return ans;
    }
};
/*
class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int firstInd = 0, lastInd=0;
        vector<int> ans;
        for (size_t i = 0; i < s.size(); i++)
        {
            int find = s.find_last_of(s[i]);
            if (find > lastInd)
                lastInd = find;
            if (i== lastInd)
            {
                ans.push_back(lastInd-firstInd+1);
                firstInd = i+1;
            }
        }
        return ans;
    }
};
*/