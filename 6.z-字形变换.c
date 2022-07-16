typedef struct
{
    int sum; // 窗口数据总和
    int front, tail;
    int size; // 窗口大小
    int *queue;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage *movingAverageCreate(int size)
{
    printf("%d\n", size);
    MovingAverage *obj = (MovingAverage *)malloc(sizeof(int) * size);
    obj->sum = 0;
    obj->front = 0;
    obj->tail = 0;
    obj->size = 0;
    obj->queue = (int *)malloc(sizeof(int) * (size + 1));
    return obj;
}

double movingAverageNext(MovingAverage *obj, int val)
{
    int size = (obj->tail - obj->front + obj->size) % (obj->size + 1);
    if (obj->size == size)
    {
        obj->sum -= obj->queue[obj->front];
        obj->front = (obj->front + 1) % (obj->size + 1);
        size--;
    }
    obj->sum += val;
    obj->queue[obj->tail] = val;
    obj->tail = (obj->tail + 1) % (obj->size + 1);
    obj->front = (obj->front + 1) % (obj->size + 1);
    size++;
    return (double)obj->sum / size;
}

void movingAverageFree(MovingAverage *obj)
{
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/