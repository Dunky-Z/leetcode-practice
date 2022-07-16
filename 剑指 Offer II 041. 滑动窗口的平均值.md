给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 `MovingAverage` 类：

`MovingAverage(int size) `用窗口大小 `size` 初始化对象。
`double next(int val)` 成员函数` next `每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 `size` 个值的移动平均值，即滑动窗口里所有数字的平均值。
 
示例：

输入：
```
inputs = ["MovingAverage", "next", "next", "next", "next"]
inputs = [[3], [1], [10], [3], [5]]
```
输出：
```
[null, 1.0, 5.5, 4.66667, 6.0]
```
解释：
```
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
```

提示：
```
1 <= size <= 1000
-105 <= val <= 105
最多调用 next 方法 104 次
```

Solution 1:

```c
typedef struct {
    int size; // 窗口大小
    int front, tail;
    int *queue;
    double sum; // 当前窗口的和
} MovingAverage;

/** Initialize your data structure here. */
MovingAverage* movingAverageCreate(int size) {
    MovingAverage *obj = (MovingAverage*)malloc(sizeof(MovingAverage));
    obj->size = size;
    obj->sum = 0;
    obj->queue = (int*)malloc(sizeof(int) * (size + 1));
    obj->front = 0;
    obj->tail = 0;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    int size = (obj->tail - obj->front + obj->size + 1) % (obj->size + 1);
    // 如果窗口满了，则需要把窗口的和减去旧的数字
    if(size == obj->size)
    {
        // 再滑动就需要将最先进入窗口的数移除
        obj->sum -= obj->queue[obj->front];
        // 将窗口首元素更新
        obj->front = (obj->front + 1) % (obj->size + 1);
        size--;
    }
    obj->queue[obj->tail] = val;
    obj->tail = (obj->tail + 1) % (obj->size + 1);
    obj->sum += val;
    size++;
    return obj->sum / size;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/

```