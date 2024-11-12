//https://kamacoder.com/problempage.php?pid=1064
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.md
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>> s;
    
    int len =s.size(), numD = 0;
    for (auto ch: s)
    {
        if(isdigit(ch))
            numD++;
    }
    int origEnd = len-1, newEnd = origEnd+numD*5;
    s.resize(newEnd+1);
    while(origEnd>=0 && newEnd>=0)
    {
        if(!isdigit(s[origEnd]))
        {
            s[newEnd--] = s[origEnd--];
        }
        else
        {
            s[newEnd--] = 'r';
            s[newEnd--] = 'e';
            s[newEnd--] = 'b';
            s[newEnd--] = 'm';
            s[newEnd--] = 'u';
            s[newEnd--] = 'n';
            origEnd--;
        }
    }
    cout<< s<<endl;
    return 0;
}

/*
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    char s[60005]={0};
    cin>> s;
    int len = strlen(s), cnt = 0, newLen=0;
    for (int i = 0; i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
            ++cnt;
    }
    newLen = len+cnt*5; //替换后原来的数字现在每个多占5个位置
    int cnk = len, newPos = newLen;
    while (cnk>=0)
    {
        if(s[cnk]>='0' && s[cnk]<='9')
        {
            s[newPos] = 'r';
            s[newPos-1] = 'e';
            s[newPos-2] = 'b';
            s[newPos-3] = 'm';
            s[newPos-4] = 'u';
            s[newPos-5] = 'n';
            newPos-=6;
            cnk--;
        }
        else
        {
            s[newPos--] = s[cnk--];
        }
    }
    cout << s<<endl;

    return 0;
}

//使用string可以更加灵活地调整空间
#include <iostream>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        int sOldIndex = s.size() - 1;
        int count = 0; // 统计数字的个数
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                count++;
            }
        }   
        // 扩充字符串s的大小，也就是将每个数字替换成"number"之后的大小
        s.resize(s.size() + count * 5);
        int sNewIndex = s.size() - 1;
        // 从后往前将数字替换为"number"
        while (sOldIndex >= 0) {
            if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9') {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            } else {
                s[sNewIndex--] = s[sOldIndex];
            }
            sOldIndex--;
        }
        cout << s << endl;       
    }
}


*/