//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
//string to int: std::stoi(); int to string: std::to_string()
//为了减少转换，统一转换为int后存放到栈，拿出来就可以使用；而不是每次从栈中取出字符串，转换成int后再计算
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> sk;
        for(auto x:tokens)
        {
            if(x=="+"|| x=="-"||x=="*" || x=="/")
            {
                int a = (sk.top());
                sk.pop();
                int b = (sk.top());
                sk.pop();
                int res=0;
                if(x=="+")
                    sk.push(a+b);
                else if(x=="-")
                    sk.push(b-a);
                else if(x=="*")
                    sk.push(b*a);
                else if(x=="/")
                    sk.push(b/a);
            }
            else
                sk.push(stoi(x));
        }
        return sk.top();
    }
};