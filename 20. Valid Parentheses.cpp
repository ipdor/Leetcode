//https://leetcode.com/problems/valid-parentheses/description/
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> sk;
        for (int i = 0; i < s.size(); i++)
        {
            if (!sk.empty() &&
                ((s[i]=='}' && sk.top()=='{') || 
                (s[i]==']' && sk.top()=='[') ||
                (s[i]==')' && sk.top()=='(')))
            {
                sk.pop();
            }
            else
                sk.push(s[i]);
        }
        return sk.empty();
    }
};