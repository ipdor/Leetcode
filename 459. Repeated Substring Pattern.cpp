//https://leetcode.com/problems/repeated-substring-pattern/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md
//高级做法2是KMP算法，当 s的最长相等前后缀不包含的子串的长度 可以被 字符串s的长度整除，那么不包含的子串 就是s的最小重复子串
//因此只需要求最长前后缀prefix数组，然后判断len(s)是否整除s最长前后缀的长度
/*例子
位置i          0    1    2    3    4    5    6    7    8    9    10    11    12    13    14    15  
前缀prefix[i] -1   -1   -1   -1    0    1    2    0    1    2    3     4     5     6     3     -1 
子串           a    g    c    t    a    g    c    a    g    c    t     a     g     c     t     g
*/
class Solution {
public:
    //getPrefix:构造prefix数组。这里前缀表统一减一，prefix[i]表示s[0]-s[i]最长前后缀最后一个字符的下标（最长前后缀长度-1）
    //1.初始化
    //2.处理前后缀不相同的情况
    //3.处理前后缀相同的情况
    void getPrefix(int *prefix, const string &s)
    {
        //1.j指向前缀末尾位置，i指向后缀末尾位置
        prefix[0] = -1;
        int j = -1; //前缀表统一减一
        for (int i = 1; i < s.size(); i++)
        {
            //2.前后缀不相等时前移
            //i=7时，j从2变成prefix[2]=-1，然后相等变成0
            //i=14时，s[14]=t!=s[j+1=7]=a,j从6变成prefix[6]=2
            //        s[14]=t==s[j+1=3]=t,相等,j=2++
            while (j>=0 && s[j+1] != s[i])
            {
                j = prefix[j];
            }
            //3.相等时复用该前后缀
            if(s[i] == s[j+1])
                j++;
            prefix[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) 
    {
        vector<int> prefix(s.size());
        getPrefix(&prefix[0], s);
        for (int x: prefix)
        {
            cout << x<< " ";
        }
        int k = prefix[prefix.size()-1];
        return k>=0 && s.size() % (s.size()-k-1) == 0;
    }
};

/*
//高级做法1是拼接s+s，然后在其中找s（注意去除s+s中首尾字符，否则会找到前面或后面的原始s）
//以abab为例，拼接后ab abab ab，中间包括abab。
string OriginalS= s;
        s+=s;
        s.erase(s.begin());
        s.erase(s.end()-1);

        return s.contains(OriginalS);
*/