//https://kamacoder.com/problempage.php?pid=1065
//不使用额外空间。思路参考https://leetcode.com/problems/reverse-words-in-a-string/description/
#include<iostream>
#include<string>
using namespace std;
inline void reverse(string &s, int left, int right)
{
    while(left < right){int tmp = s[left]; s[left++] = s[right]; s[right--] = tmp;}
}

int main()
{
    string s;
    int k;
    cin>> k;
    cin >> s;
    //reverse all
    int left =0, right = s.size()-1;
    reverse(s,0, s.size()-1);
    //cout << s << endl;
    //reverse first k characters and last n-k characters seperately
    left =0, right = k-1;
    reverse(s, 0, k-1);

    reverse(s, k, s.size()-1);

    cout << s << endl;
    return 0;
}