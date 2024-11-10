//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md
//https://blog.csdn.net/yearn520/article/details/6729426
/*例子
位置i          0    1    2    3    4    5    6    7    8    9    10    11    12    13    14    15  
前缀next[i]    0    0    0    0    1    2    3    1    2    3    4     5     6     7     4     0  
子串           a    g    c    t    a    g    c    a    g    c    t     a     g     c     t     g
*/
class Solution {
public:
    void getPrefix(int* prefix, const string &haystack)
    {
        prefix[0] = 0;
        int j=0;
        for (int i = 1; i < haystack.size(); i++)
        {
            //1.不断前移，尝试找重复前后缀。
            //i=14为例，j依次为prefix[13]=7, 代表最长前缀agctagc的长度，匹配haystack[j==7]和haystack[14]失败，继续往前找前缀
            //j=prefix[7-1]=3, 代表次长前缀agc的长度，匹配haystack[j==3]和haystack[14]成功
            while (haystack[j] != haystack[i] && j>0)
            {
                j = prefix[j-1]; //找到上个相同前缀
            }
            //2.相等+1
            if(haystack[j] == haystack[i] )
                j++;
            //3.还不等说明没有相等前缀
            prefix[i] = j;
        }
    }

    int strStr(string haystack, string needle) 
    {
        //prefix[i]存放needle[0-i]的最长相同前后缀长度
        int *prefix = (int *)malloc(sizeof(int)*needle.size());
        getPrefix(prefix, needle);
        // for (int i = 0; i < needle.size(); i++)
        // {
        //     cout<< prefix[i] << " ";
        // }
        int j =0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while(j>0 && haystack[i] != needle[j])
            {
                //如果和needle[j]不相等，那么和其最长前缀的needle[j]匹配
                j = prefix[j-1];
            }
            if(haystack[i] == needle[j])
                j++;
            if(j==needle.size())
                return i-needle.size()+1;
        }

        return -1;
    }
};
