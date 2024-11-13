//https://leetcode.com/problems/sliding-window-maximum/description/
//维护一个单调非增栈，，永远确保头部是最大值。内部不需要维护所有元素
//大元素左侧的小元素用不到，1是它们不可能成为最大值，2是去掉它可以方便找最大元素；相反右侧的小元素可能在大元素被移除后变成最大元素，不能去除。
class dque{
private:
    std::deque<int> q;
public:
    //每次插入前把前面小于value的元素去除，确保队列内元素单调递减
    void push(int value)
    {
        while(!q.empty() && q.back() < value)
        {
            q.pop_back();
        }
        q.push_back(value);
    }
    //只有当front=value时说明确实需要移除元素，其他情况时元素根本不在队列内
    void pop(int value)
    {
        if(!q.empty() && value==q.front())
            q.pop_front();
    }
    int getMax()
    {
        return q.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(k==1)
            return nums;
        dque win;
        vector<int> res;
        for (int i = 0;i<nums.size(); i++)
        {
            win.push(nums[i]);
            if(i>=k-1)
            {
                if(i-k >=0)
                    win.pop(nums[i-k]);
                res.push_back(win.getMax());
            }
        }
        return res;
    }
};