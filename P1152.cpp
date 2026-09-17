#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    int v[n],count[n] = {0};
    for (size_t i = 0; i < n; i++)
    {
        cin >>v[i];
    }
    for (size_t i = 1; i < n; i++)
    {
        int abs_a = abs(v[i]-v[i-1]);
        if (abs_a >= 1 &&abs_a < n)
        {
            count[abs_a]++;
        }
        
    }
    bool is_jolly = 1;
    for (size_t i = 1; i < n; i++)
    {
        if (count[i] == 0)
        {
            is_jolly = 0;
            break;
        }
    }
    if (is_jolly)
    {
        cout <<"Jolly";
    }
    else cout <<"Not jolly";
}

/*# P1152 欢乐的跳

## 题目描述

一个 $n$ 个元素的整数数组，如果数组两个连续元素之间差的绝对值包括了 $[1,n-1]$ 之间的所有整数，则称之符合“欢乐的跳”，如数组 $\{1,4,2,3\}$ 符合“欢乐的跳”，因为差的绝对值分别为：$3,2,1$。

给定一个数组，你的任务是判断该数组是否符合“欢乐的跳”。

## 输入格式

每组测试数据第一行以一个整数 $n(1 \le n \le 1000)$ 开始，接下来 $n$ 个空格隔开的在 $[-10^8,10^8]$ 之间的整数。

## 输出格式

对于每组测试数据，输出一行若该数组符合“欢乐的跳”则输出 `Jolly`，否则输出 `Not jolly`。

## 输入输出样例 #1

### 输入 #1

```
4 1 4 2 3

```

### 输出 #1

```
Jolly

```

## 输入输出样例 #2

### 输入 #2

```
5 1 4 2 -1 6
```

### 输出 #2

```
Not jolly
```

## 说明/提示

$1 \le n \le 1000$*/