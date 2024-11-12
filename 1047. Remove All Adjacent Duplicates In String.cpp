//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
//1.使用栈进行“消消乐”，最后把栈中字符组成字符串并逆转，时间空间复杂度O(n)
//2.直接使用字符串当作栈，空间复杂度O(1)，时间复杂度O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto ch:s)
        {
            if (res.size()==0 || res.back()!=ch)
            {
                res.push_back(ch);
            }
            else
                res.pop_back();
        }
        return res;
    }
};