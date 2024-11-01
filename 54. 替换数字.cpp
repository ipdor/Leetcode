//https://kamacoder.com/problempage.php?pid=1064
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.md
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s, news;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            news+=s[i];
        else
            news+="number";
    }
    cout<< news;
    return 0;
}