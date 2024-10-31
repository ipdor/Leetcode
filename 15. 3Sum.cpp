//https://leetcode.com/problems/3sum/description/
//https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        //3个下标i,left,right分别指向排序后数组中一个数字
        //遍历i，每次从右边找到和=-nums[i]的2个数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]>0)
            {
                break;
            }
            //避免i相同导致找到重复元组
            if (i>0 && nums[i-1]==nums[i])
            {
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while (left<right)
            {
                if (nums[left] + nums[right] < -nums[i])
                {
                    left++;
                }
                else if (nums[left] + nums[right] > -nums[i])
                {
                    right--;
                }
                else
                {
                    vector<int> pair{nums[i], nums[left], nums[right]};
                    res.push_back(pair);
                    //避免left和right相同导致找到重复元组
                    while (left<right && nums[left+1] == nums[left])
                        left++;
                    while (left<right && nums[right-1] == nums[right])
                        right--;
                    left++; //不循环/循环后仍然指向相同的数，需要移动一位才会变更nums[left]/nums[right]，否则这里陷入死循环
                    right--;
                }
            }
        }
        return res;
    }
};