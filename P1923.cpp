#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void quick_short(vector<long long>::iterator v,long long len,long long locate){
    if (len <= 1)
    {
        return;
    }
    
    long long i = 0,j = 0,k = len;
    long long pivot = v[rand()%len];
    while (i < k)
    {
        if (v[i] < pivot)
        {
            swap(v[i++],v[j++]);
        }
        else if (v[i] > pivot)
        {
            swap(v[i],v[--k]);
        }
        else i++;        
    }
    quick_short(v,j,locate);
    quick_short(v+k,len - k,locate);
}
int main(){
    long long k,n,temp;
    vector<long long> v;
    scanf("%lld %lld",&n,&k);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&temp);
        v.push_back(temp);
    }
    quick_short(v.begin(),v.size(),k);
    printf("%lld",v[k]);
}

// ==================== 洛谷题目描述 ====================
// 来源：https://www.luogu.com.cn/problem/P1923
//
// # P1923 【深基9.例4】求第 k 小的数
//
// ## 题目描述
//
// 输入 $n$ 个数字 $a_i$，输出这些数字中第 $k$ 小的数。最小的数是第 $0$ 小。 请尽量不要使用 `nth_element` 来写本题，因为本题的重点在于练习分治算法。
//
// ## 输入格式
//
// 第一行有两个整数，分别表示 $n$ 和 $k$。 第二行有 $n$ 个整数，第 $i$ 个数表示 $a_i$。
//
// ## 输出格式
//
// 一个整数，表示第 $k$ 小的数。
//
// ## 说明/提示
//
// 对于 $100\%$ 的数据，$1\le a_i<{10}^9$，$1 \le n < 5\times 10^6$，且 $n$ 为奇数。
