---
title: 剑指 Offer 59 - II. 队列的最大值
tags: LeetCode,队列
notebook: 
---

请定义一个队列并实现函数 `max_value` 得到队列里的最大值，要求函数`max_value`、`push_back` 和 `pop_front` 的均摊时间复杂度都是`O(1)`。

若队列为空，`pop_front` 和 `max_value` 需要返回 `-1`

示例 1：
```cpp
输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
```
示例 2：
```cpp
输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
```

限制：
```
1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5
```

---

Solution 1:

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() 
    {
        if(dque.empty())
            return -1;
        else
            return dque.front();
    }
    
    void push_back(int value) 
    {
        que.push(value);
        //如果双端队列不为空，并且待加入值大于队尾，将队尾元素删除。
        //因为双端队列始终保持递减
        while(!dque.empty() && dque.back() < value)
            dque.pop_back();
        dque.push_back(value);
    }
    
    int pop_front() 
    {
        if(que.empty())
            return -1; 
        int val = que.front();
        que.pop();
        if(val == dque.front())
            dque.pop_front();
        return val;
    }
private:
    queue<int> que;
    deque<int> dque;//保持始终递减
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```