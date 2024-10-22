//https://leetcode.com/problems/remove-element/

class Solution {
public:
    //快慢指针
    //0ms Beats 100.00%
    int removeElement(vector<int>& nums, int val) 
    {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast]!=val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};