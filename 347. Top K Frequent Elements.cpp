//https://leetcode.com/problems/top-k-frequent-elements/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.md
//整体思路：
//1.map统计频率
//2.生成优先级队列，实现最小堆的比较函数
//3.把每个map的pair加入优先级队列，保持数量为k，大于k时弹出最小的数
//4.弹出最小堆，倒着插入result结果集
//时间复杂度度O(n * logk)
class Solution {
public:
    class MyCompare{
    public:
        bool operator ()(pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> map;
        for(auto x:nums)
            map[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, MyCompare> minDump;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            //typeid 是唯一在运行时可以提供类型名称的方式。它可以返回一个经过编译器符号化的名称，虽然不可读，但可以提供一些线索
            //Leetcode输出"St4pairIKiiE"
            //cout<<typeid(*it).name()<<endl; 
            //优先级队列push操作时间复杂度O(log n)，n是元素个数，本题是O(log K)
            minDump.push(*it);
            if(minDump.size()>k)
            {
                minDump.pop();
            }
        }
        vector<int> res(k);
        for (int i = k-1; i >=0; i--)
        {
            res[i] = minDump.top().first;
            //cout<< minDump.top().first << " ";
            minDump.pop();
        }
        //cout << endl;
        
        return res;
    }
};