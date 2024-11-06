//https://leetcode.com/problems/reverse-words-in-a-string/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md
class Solution {
public:
    //这个trim实际没用到
    void trim(string &s)
    {
        //trim right
        int spaceCnt = 0;
        for (int i = s.size()-1; i >=0 ; i--)
        {
            if (s[i]==' ')
            {
                spaceCnt++;
            }
            else 
                break;
        }
        s.resize(s.size()-spaceCnt);

        //trim left
        spaceCnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]==' ')
            {
                spaceCnt++;
            }
            else 
                break;
        }
        int left = 0, right = spaceCnt;
        while (right < s.size())
        {
            s[left++] = s[right++];
        }
        s.resize(left);
    }

    string reverseWords(string s) 
    {
        //trim spaces同时trim前后中间的空格，参考力扣027移除元素
        int slow = 0, fast = 0;
        for(; fast< s.size() && s[fast]==' '; fast++);
        for(; fast< s.size(); fast++)
        {
            if (fast>0 && s[fast-1]==' ' && s[fast]==' ')
            {
                continue;
            }
            else
            {
                s[slow++] = s[fast];
            }
        }
        s.resize(s[slow-1] == ' '?slow-1: slow);
        //cout<<"\""<<s<<"\""<<endl;

        //reverse all characters
        for (int i = 0; i < s.size()/2; i++)
        {
            char tmp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = tmp;
        }
        //cout<<"\""<<s<<"\""<<endl;

        //reverse words again
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i>0 && s[i-1] == ' ')
                j = i;
            if (i==s.size()-1 || s[i+1]==' ')
            {
                //cout<< "此时j和i的值：" << j<<" "<< i <<endl;
                int left = j, right = i;
                while (left<right)
                {
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
            }
        }
        return s;
    }
};

/*
* 关键点：
* 1. erase和find_if函数搭配，对string进行trim（注意ltrim和rtrim区别，包括.base使用）
* 2. 去除空格中迭代器的逆向使用
* 3. 时间复杂度是多少？去除多余空格的循环最坏情况下为 O(n^2)，reverse操作为O(n)  记住erase操作为O(n)！！！
* 4. 如何不用辅助空间并且时间复杂度O(n)解决？

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
*/