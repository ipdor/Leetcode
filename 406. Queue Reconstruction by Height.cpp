//https://leetcode.com/problems/queue-reconstruction-by-height/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0406.%E6%A0%B9%E6%8D%AE%E8%BA%AB%E9%AB%98%E9%87%8D%E5%BB%BA%E9%98%9F%E5%88%97.md
//先考虑身高h再考虑k。一定是往高个里面插入矮个，这样不会影响k
bool comp(vector<int> &a, vector<int>&b)
{
    return a[0]==b[0]? a[1]<b[1] : a[0]>b[0];
}
//list的插入效率O(1)，整体效率O(n)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), comp);
        list<vector<int>> ans;
        for (size_t i = 0; i < people.size(); i++)
        {
            int k = people[i][1];
            auto it = ans.begin();
            for (; it!=ans.end() && k>0; it++) //可以直接循环k--，因为前面一定是高度大于等于它的
                if ((*it)[0] >= people[i][0]) 
                    k--;
            ans.insert(it, people[i]);
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
//vector版本，效率O(n2)
// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
//     {
//         sort(people.begin(), people.end(), comp);
//         vector<vector<int>> ans;
//         for (size_t i = 0; i < people.size(); i++)
//         {
//             int k = people[i][1], j=0;
//             for (; j < ans.size()&& k>0; j++)
//             {
//                 if (ans[j][0]>= people[i][0])
//                     k--;
//             }
//             ans.insert(ans.begin()+j,people[i]);
//             // for (size_t i = 0; i < ans.size(); i++)
//             //     cout<< ans[i][0] <<","<< ans[i][1] << " ";
//             // cout<<endl;
//         }
//         return ans;
//     }
// };