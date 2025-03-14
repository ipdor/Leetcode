//https://leetcode.com/problems/reconstruct-itinerary/
//这道题比较考察数据结构。直接用标准回溯法+used数组会超时
//src2dest_cnt的key是起始地，value是保存多个映射的map，每个map是<目的地，通往到这条路的次数>
//每次根据src从unordered_map中找到第一个cnt>0的map<dst, cnt>，然后继续。由于map本身有序，所以不需要单独排序
using src2dest_cnt = unordered_map<string, map<string, int>>;
class Solution {
public:
    int routeCnt;
    // void print(src2dest_cnt &routes)
    // {
    //     for(auto x: routes)
    //     {
    //         cout<< x.first<< endl;
    //         for (auto y:x.second)
    //         {
    //             cout << "   "<< y.first <<":" << y.second <<endl;
    //         }
    //     }
    //     cout<< endl;
    // }
    bool traceback(src2dest_cnt &routes, const string &nextSta, vector<string>& ans)
    {
        if (ans.size() == routeCnt)
            return true;
        
        for(auto it =routes[nextSta].begin(); it!=routes[nextSta].end(); it++)
        {
            if(it->second<=0)
                continue;
            ans.push_back(it->first);
            it->second--;
            //cout<<"From "<< nextSta<< " to " <<it->first <<" "<<it->second <<endl;
            if(traceback(routes, it->first, ans))
                return true;
            it->second++;
            ans.pop_back();
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        vector<string> ans;
        routeCnt = tickets.size()+1;
        src2dest_cnt routes;
        for (auto x: tickets)
        {
            //c[k] 返回关键字为k的元素: 如果k不在c中，添加一个关键字为k的元素，对其进行值初始化。所以可以不单独处理不存在的情况
            // if(routes.find(x[0]) == routes.end())
            //     routes[x[0]] = map<string, int>{make_pair(x[1], 1)};
            // else
                routes[x[0]][x[1]]++;
        }
        //print(routes);
        ans.push_back("JFK");
        traceback(routes, "JFK", ans);
        return ans;
    }
};