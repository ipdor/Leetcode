//https://leetcode.com/problems/simplify-path/description/
//也可以使用vector<string>作为栈，不过没有本质区别，最后也需要倒到res中
class Solution {
public:
    string simplifyPath(string path) 
    {
        path+="/";
        string dir;
        stack<string> st;
        for(auto x: path)
        {
            if(x!='/')
            {
                dir+=x;
            }
            else if(dir!="")
            {
                //cout<<dir<<endl;
                if(dir == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else if(dir !=".")
                {
                    st.push(dir);
                }
                dir="";
            }

        }
        string res;
        while(!st.empty())
        {
            res="/"+st.top()+res;
            st.pop();
        }
        return res.size()?res:"/";
    }
};