---
title: OJ在线编程处理输入输出练习
tags: LeetCode
notebook: a - 001 | ITabc
---


https://ac.nowcoder.com/acm/contest/5649?from=hr_test#question

#### 计算a+b

输入描述:
```
输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据包括多组。
```
输出描述:
```
输出a+b的结果
```
示例1
```
输入
1 5
10 20
```
```
输出
6
30
```

```cpp
#include <iostream>
using namespace std;
int main()
{
    long long a , b;
    while(cin >> a >> b)
    {
        cout << a+b << endl;
    }
    return 0;
}
```

#### 计算a+b

输入描述:
```
输入第一行包括一个数据组数t(1 <= t <= 100)
接下来每行包括两个正整数a,b(1 <= a, b <= 10^9)
```
输出描述:
```
输出a+b的结果
```

示例1
```
输入
2
1 5
10 20
```
```
输出
6
30
```

```cpp
#include <iostream>
using namespace std;
int main()
{
    int siz;
    long long a , b;
    cin >> siz;
    while(siz--)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
```


