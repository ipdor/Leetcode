//https://leetcode.com/problems/repeated-substring-pattern/
//高级做法是拼接s+s，然后在其中找s（注意去除s+s中首尾字符，否则会找到前面或后面的原始s）
//以abab为例，拼接后ab abab ab，中间包括abab。
class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        string OriginalS= s;
        s+=s;
        s.erase(s.begin());
        s.erase(s.end()-1);

        return s.contains(OriginalS);
    }
};


/*
//简单做法是暴力遍历
class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        //s若重复至少需要是aa结构
        for(int i = 1; i<=s.size()/2; i++)
        {
            //前i个字符和后面每i个字符轮流对比
            int left = 0, right=left+i, valid=true;
            while (right<s.size())
            {
                //cout <<"i="<< i <<", s[left]="<< s[left]<< ", s[right]="<< s[right]<<endl;
                if(s[left++]!=s[right++])
                {
                    valid = false;
                    break;
                }
                left = left%i;
            }
            //如果符合，上面left刚匹配完全词回到下标0,否则指向中间，如aabaaba最后left指向第二个a
            if(valid&&left == 0)
                return true;
        }
        return false;
    }
};
*/