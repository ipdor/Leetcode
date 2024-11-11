//https://leetcode.com/problems/implement-queue-using-stacks/description/
class MyQueue {
private:
    std::stack<int> *skIn;
    std::stack<int> *skOut;
public:
    MyQueue() {
        skIn = new std::stack<int>();
        skOut = new std::stack<int>();
    }
    
    void push(int x) {
        skIn->push(x);
    }
    
    int pop() {
        if(skOut->empty())
        {
            while (!skIn->empty())
            {
                skOut->push(skIn->top());
                skIn->pop();
            }
        }
        int k = skOut->top();
        skOut->pop();
        return k;
    }
    
    //从Out栈栈顶中取出来，再放入栈顶，不影响。
    int peek() {
        int k = pop();
        skOut->push(k);
        return k;
    }
    
    bool empty() {
        return skIn->empty() && skOut->empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */