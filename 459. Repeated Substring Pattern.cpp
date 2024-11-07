//https://leetcode.com/problems/repeated-substring-pattern/
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