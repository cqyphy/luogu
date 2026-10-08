#include <iostream>
#include <iomanip>
using namespace std;
int n;
int a[10];
void dfs(int step){
    if (step == n)
    {
        for (size_t j = 0; j < step; j++)
        {
            cout <<setw(5)<<a[j];
        }
        cout <<endl;
        return;
    }
    
    for (size_t i = 1; i < n+1; i++)
    {
        bool bool_a = 0;
        for (size_t k = 0; k < step; k++)
        {
            if (i == a[k])
            {
                bool_a = 1;
                break;
            }
            
        }
        if (bool_a)
        {
            continue;
        }
        
        a[step] = i;
        dfs(step + 1);
    }
    
}
int main(){
    cin >>n;
    dfs(0);
    //system("pause");
}

/*# P1706 全排列问题

## 题目描述

按照字典序输出自然数 $1$ 到 $n$ 所有不重复的排列，即 $n$ 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

## 输入格式

一个整数 $n$。

## 输出格式

由 $1 \sim n$ 组成的所有不重复的数字序列，每行一个序列。

每个数字保留 $5$ 个场宽。

## 输入输出样例 #1

### 输入 #1

```
3
```

### 输出 #1

```
    1    2    3
    1    3    2
    2    1    3
    2    3    1
    3    1    2
    3    2    1

```

## 说明/提示

$1 \leq n \leq 9$。*/