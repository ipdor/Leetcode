//https://leetcode.com/problems/find-common-characters/description/
#define min(a,b) ((a)<(b)?(a):(b))
class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int> alpha(26,0);
        for (int i = 0; i < words[0].size(); i++)
            alpha[words[0][i] - 'a']++;

        for (int cnt = 1; cnt < words.size(); cnt++)
        {
            vector<int> alpha1(26,0);
            for (int i = 0; i < words[cnt].size(); i++)
                alpha1[words[cnt][i] - 'a']++;
            for (int i = 0; i < alpha.size(); i++)
                alpha[i] = min(alpha[i], alpha1[i]);
        }

        vector<string> res;
        for (int i = 0; i < alpha.size(); i++)
        {
            int a= alpha[i];
            while (a--)
            {
                char str[5] = {0};
                str[0] = i + 'a';
                res.push_back(string(str));
            }
        }
        return res;
    }
};