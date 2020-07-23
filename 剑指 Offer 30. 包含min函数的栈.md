---
title: 剑指 Offer 30. 包含min函数的栈
tags: LeetCode,栈
notebook: a - 001 | ITabc
---
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
示例:
```cpp
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```

提示：
```
各函数的调用总次数不超过 20000 次
```

---

Solution 1:

```cpp

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {    }
    
    void push(int x) 
    {
        stk1.push(x);
        if(stk2.empty() || x < stk2.top())
            stk2.push(x);
        else 
            stk2.push(stk2.top());
    }
    
    void pop() 
    {
        stk1.pop();
        stk2.pop();
    }
    
    int top() 
    {
        return stk1.top();
    }
    
    int min() 
    {
        return stk2.top();
    }
private:
    stack<int> stk1, stk2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```