//https://leetcode.com/problems/candy/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0135.%E5%88%86%E5%8F%91%E7%B3%96%E6%9E%9C.md
//分别从左向右看左确定右边大小、从右向左看右确定左边大小。最后逐个取最大值
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> canAllo(ratings.size(), 1);
        for (size_t i = 1; i < ratings.size(); i++)
        {
            canAllo[i] = ratings[i]>ratings[i-1]? canAllo[i-1]+1:1;
        }
        //减小的情况注意不能用size_t
        for (int i = ratings.size()-2; i >=0; i--)
        {
            canAllo[i] = max(canAllo[i], ratings[i]>ratings[i+1]? canAllo[i+1]+1:1);
        }

        int sum=0;
        for (size_t i = 0; i < ratings.size(); i++)
        {
            //cout<< canAllo[i]<< " ";
            sum+= canAllo[i];
        }
        // cout<< endl;
        return sum;
    }
};