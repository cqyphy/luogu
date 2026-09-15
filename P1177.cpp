#include <iostream>
using namespace std;
template <typename T>
void quick_sort(T arr[],int len){
    if (len <= 1)
    {
        return ;
    }
    const T pivot = arr[rand()%len];
    int i = 0,j = 0,k = len;
    while (i < k)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i++],arr[j++]);
        }
        else if (pivot < arr[i])
        {
            swap(arr[i],arr[--k]);
        }
        else i++;
    }
    quick_sort(arr,j);
    quick_sort(arr+k,len-k);
}
int main(){
    int n;
    cin >>n;
    int v[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >>v[i];
    }
    quick_sort(v,n);
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i]<<' ';
    }
    system("pause");
}

// ==================== 洛谷题目描述 ====================
// 来源：https://www.luogu.com.cn/problem/P1177
//
// # P1177 【模板】排序
//
// ## 题目描述
//
// 将读入的 $N$ 个数从小到大排序后输出。
//
// ## 输入格式
//
// 第一行为一个正整数 $N$。 第二行包含 $N$ 个空格隔开的正整数 $a_i$，为你需要进行排序的数。
//
// ## 输出格式
//
// 将给定的 $N$ 个数从小到大输出，数之间空格隔开。
//
// ## 说明/提示
//
// 对于 $20\%$ 的数据，有 $1 \leq N \leq 10^3$； 对于 $100\%$ 的数据，有 $1 \leq N \leq 10^5$，$1 \le a_i \le 10^9$。
