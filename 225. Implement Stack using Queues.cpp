//https://leetcode.com/problems/implement-stack-using-queues/description/
//每次pop时先把前面size-1个元素取出放到后面，再pop
class MyStack {
private:
    std::queue<int> *que;
public:
    MyStack() {
        que = new std::queue<int>();
    }
    
    void push(int x) {
        que->push(x);
    }
    
    int pop() {
        int len = que->size()-1, k = que->back();
        while (len--)
        {
            que->push(que->front());
            que->pop();
        }
        que->pop();
        return k;
    }
    
    int top() {
        //如果不能用back函数，只需要pop函数的最后也执行que->push(que->front())再pop
        return que->back();
    }
    
    bool empty() {
        return que->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */