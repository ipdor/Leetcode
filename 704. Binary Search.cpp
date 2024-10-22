//https://leetcode.com/problems/binary-search/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        int mid = (beg+end)/2;
        if (nums[beg]==target)
            return 0;
        else if (nums[end]==target)
            return end;

        while (beg<=end)
        {
            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                beg = mid+1;
            else if (nums[mid] > target)
                end = mid-1;
            mid = (beg+end)/2;
        }
        
        return -1;
    }
};