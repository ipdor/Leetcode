//https://leetcode.com/problems/reverse-words-in-a-string/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md
/*
* 关键点：
* 1. erase和find_if函数搭配，对string进行trim（注意ltrim和rtrim区别，包括.base使用）
* 2. 去除空格中迭代器的逆向使用
* 3. 时间复杂度是多少？去除多余空格的循环最坏情况下为 O(n^2)，reverse操作为O(n)  记住erase操作为O(n)！！！
* 4. 如何不用辅助空间并且时间复杂度O(n)解决？
*/
class Solution {
public:
    void ltrim(string &s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch){return !isspace(ch);}) );
    }

    void rtrim(string &s)
    {
        s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch){return !isspace(ch);}).base(), s.end());
    }
    string reverseWords(string s) 
    {
        //trim
        ltrim(s);
        rtrim(s);
        //reduce multiple spaces
        for (auto iter = s.rbegin(); iter < s.rend(); iter++)
        {
            if(*iter == ' ' && *(iter-1) == ' ' )
            {
                s.erase(iter.base()); // erase只接收正向迭代器, 需要base转换
            }
        }
        //reverse
        //为什么2个循环但是复杂度O(n)？极限法考虑：
        //1.只有1个很长的单词，此时外循环一次，内循环复制各个字母到res，O(n)
        //2.每个单词只有1个字母，每个单词之间一个空格，如"a b c d e f"。外循环n次，内循环每次复制1个字母或空格，O(n)
        string res;
        res.resize(s.size());
        int begin = s.size()-1, end = s.size()-1, pos = 0;
        while (begin>=0 && end>=0)
        {
            //去除空格
            if (s[begin]==' ')
            {
                res[pos++] = s[begin--];
                end = begin;
                continue;
            }
            //[begin, end]确定一个单词,然后借助cur移动
            while (begin>0 && s[begin-1]!=' ')
            {
                begin--;
            }
            int cur = begin--;
            while (cur<=end)
            {
                res[pos++] = s[cur++];
            }
        }
        // cout<< s<<endl;
        // cout<< res<<endl;

        return res;
    }
};