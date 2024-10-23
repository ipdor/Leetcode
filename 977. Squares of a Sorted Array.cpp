//https://leetcode.com/problems/squares-of-a-sorted-array/description/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i]*nums[i];
        }

        vector<int> sortednums(nums.size());
        int sortedEnd = nums.size()-1;
        int left = 0, right = nums.size()-1;

        while(left<=right)
        {
            if(nums[left]> nums[right])
            {
                sortednums[sortedEnd--] = nums[left++];
            }
            else
                sortednums[sortedEnd--] = nums[right--];
        }
        return sortednums;
    }
};