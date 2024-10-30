//https://leetcode.com/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int,int> umap;

        int sum = 0, n = nums1.size();
        for (int i = 0; i< n; i++)
        {
            for (int j = 0; j< n; j++)
            {
                umap[nums1[i]+nums2[j]]++;
            }
        }

        for (int i = 0; i< n; i++)
        {
            for (int j = 0; j< n; j++)
            {
                if (umap.find(0-nums3[i]-nums4[j]) != umap.end())
                    sum+=umap[0-nums3[i]-nums4[j]];
            }
        }
        return sum;
    }
};



/*
# 实际运行速度的比较

尽管两者的时间复杂度是相同的，但在实际运行中，第一种方案可能更快，原因如下：

    unordered_map vs unordered_multiset：
        在第一段代码中，unordered_map 只存储每个和的出现次数，所以它的空间使用更节约，插入和查找操作也会更高效。
        在第二段代码中，unordered_multiset 不仅存储了和的值，还存储了所有的重复元素。由于 unordered_multiset 
        需要存储更多的重复数据，在内存和缓存性能方面可能表现稍差。

    查找次数：
        在第一段代码中，查找的操作直接返回存储的次数。
        在第二段代码中，查找使用的是 count()，这涉及遍历 unordered_multiset 的桶来计算元素出现的次数，
        这可能比直接访问 unordered_map 的键值对稍慢。

# 结论：

    理论时间复杂度相同，都是 O(n^2)。
    实际运行速度：第一种代码（使用 unordered_map）通常会更快，因为 unordered_map 的插入和查找效率更高，
    并且只记录每个和的频次，而不需要存储重复的和。

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_multiset<int> umset1,umset2;

        int sum = 0, n = nums1.size();
        for (int i = 0; i< n; i++)
        {
            for (int j = 0; j< n; j++)
            {
                umset1.insert(nums1[i]+nums2[j]);
                umset2.insert(nums3[i]+nums4[j]);
            }
        }
        for (int num: umset1)
        {
            sum+=umset2.count(0-num);
        }
        return sum;
    }
};
*/