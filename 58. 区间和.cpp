//https://kamacoder.com/problempage.php?pid=1070
//前缀和
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int lines=0;
    cin>> lines;
    vector<int> nums, sums;
    int sumNow = 0;
    while (lines--)
    {
        int a=0;
        cin>> a;
        sumNow+=a;
        nums.push_back(a);
        sums.push_back(sumNow);
    }

    int beg = -1, end=-1;
    while (cin>> beg >> end)
    {
        cout<< sums[end] - (beg>0?sums[beg-1]:0)<< endl;
    }
}