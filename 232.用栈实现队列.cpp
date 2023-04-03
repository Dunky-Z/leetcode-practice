/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
    stack<int> stacka;
    stack<int> stackb;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stacka.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int len =  stacka.size();
        for(int i = 0; i < len; i++)
        {
            stackb.push(stacka.top());
            stacka.pop();
        }
        int var = stackb.top();
        stackb.pop();
        for(int j = 0; j < len - 1; j++)
        {
             stacka.push(stackb.top());
            stackb.pop();
        }
        return var;
    }
    
    /** Get the front element. */
    int peek() {
        int len =  stacka.size();
        for(int i = 0; i < len; i++)
        {
            stackb.push(stacka.top());
            stacka.pop();
        }
        int var = stackb.top();
        for(int j = 0; j < len; j++)
        {
             stacka.push(stackb.top());
            stackb.pop();
        }
        return var;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stacka.empty() && stackb.empty();
          
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
// @lc code=end

