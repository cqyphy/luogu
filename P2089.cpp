#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> v (10) ;
int n ;
vector<vector<int>> vari_v;
void funtion(int pos,int sum){
    if (pos == 10)
    {
        if (sum == n)
        {
            vari_v.push_back(v);
        }        
        return ;
    }
    for (size_t i = 1; i <= 3; i++)
    {
        v[pos] = i;
        funtion(pos+1,sum+i);
    }        
}
int main(){
    cin >>n;
    if (n<10 ||n > 30)
    {
        cout <<vari_v.size();
        return 0;
    }
    funtion(0,0);
    cout << vari_v.size()<<endl;
    for (size_t i = 0; i < vari_v.size(); i++)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            cout <<vari_v[i][j]<<' ';
        }
        cout <<endl;
    }
    
    system("pause");
}

/*# P2089 烤鸡

## 题目背景

猪猪 Hanke 得到了一只鸡。

## 题目描述

猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 $10$ 种配料（芥末、孜然等），每种配料可以放 $1$ 到 $3$ 克，任意烤鸡的美味程度为所有配料质量之和。

现在， Hanke 想要知道，如果给你一个美味程度 $n$ ，请输出这 $10$ 种配料的所有搭配方案。

## 输入格式

一个正整数 $n$，表示美味程度。

## 输出格式

第一行，方案总数。

第二行至结束，$10$ 个数，表示每种配料所放的质量，按字典序排列。

如果没有符合要求的方法，就只要在第一行输出一个 $0$。

## 输入输出样例 #1

### 输入 #1

```
11
```

### 输出 #1

```
10
1 1 1 1 1 1 1 1 1 2 
1 1 1 1 1 1 1 1 2 1 
1 1 1 1 1 1 1 2 1 1 
1 1 1 1 1 1 2 1 1 1 
1 1 1 1 1 2 1 1 1 1 
1 1 1 1 2 1 1 1 1 1 
1 1 1 2 1 1 1 1 1 1 
1 1 2 1 1 1 1 1 1 1 
1 2 1 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 1 1 
```

## 说明/提示

对于 $100\%$ 的数据，$n \leq 10000$。*/