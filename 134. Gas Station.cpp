//https://leetcode.com/problems/gas-station/
//总思路是加油量>=耗油量，并且在旅程结束之前结余(当前加油量-当前耗油量)>=0
//每一次合法旅程都满足条件：1. 当前加油量-当前耗油量>=0；并且
//2.固定顺时针绕圈：也就是左侧可能有不满足条件的起点，但右侧一定是合法旅程。[非法起点] 合法起点 合法加油站
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int sum=0;
        for (size_t i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
        }
        if (sum<0)
            return -1;
        int ans=0, curbalance=0;
        for (size_t i = 0; i < gas.size(); i++)
        {
            curbalance += gas[i] - cost[i];
            //旅途中间就出现了耗油量大于加油量，一定不可行
            //假设下个是合法起点
            if (curbalance<0)
            {
                ans = i+1;
                curbalance = 0;
            }
        }
        return ans;
    }
};

//下面的代码比较繁琐，确定加油量>=耗油量后，查找了从哪个点出发能获得最长结余>0
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
//     {
//         vector<int> balance(gas.size(),0);
//         int gastotal = 0, costtotal=0;
//         for (size_t i = 0; i < gas.size(); i++)
//         {
//             balance[i] = gas[i] - cost[i];
//             gastotal+= gas[i];
//             costtotal+=cost[i];
//             cout<< balance[i] << " ";
//         }
//         cout<< endl;
//         if(costtotal> gastotal)
//             return -1;
//         int indMax=0, maxconpossum=0, conpossum=0, sum=0;
//         for (size_t i = 0; i < balance.size(); i++)
//         {
//             sum+=balance[i];
            
//             if (sum>0)
//             {
//                 if (conpossum==0)
//                     indMax = i;
//                 conpossum++;
                
//                 if (conpossum> maxconpossum)
//                     maxconpossum = conpossum;
//             }
//             else
//             {
//                 sum=0;
//                 conpossum = 0;
//             }
//         }

//         cout<< indMax << " "<< maxconpossum << endl;
//         for (size_t i = 0; i < balance.size(); i++)
//         {
//             sum+=balance[i];
            
//             if (sum>0)
//             {
//                 if (conpossum==0)
//                     indMax = i;
//                 conpossum++;
                
//                 if (conpossum> maxconpossum)
//                     maxconpossum = conpossum;
//             }
//             else
//             {
//                 sum=0;
//                 conpossum = 0;
//             }
//         }
//         cout<< indMax << " "<< maxconpossum << endl;
//         return indMax;
//     }
// };