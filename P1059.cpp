#include <iostream>
#include <vector>
using namespace std;
void bubble_sort(int v[],int len){
    for (size_t i = 0; i < len-1; i++)
    {
        for (size_t j = 0; j < len -i-1; j++)
        {
            if (v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
            
        }
        
    }
    
}
int main(){
    int n;
    cin >> n;
    int v[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bubble_sort(v,n);
    vector<int> variable_v;
    for (size_t i = 0; i < n; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        variable_v.push_back(v[i]);
    }
    cout << variable_v.size()<<endl;
    for (auto i = variable_v.begin(); i != variable_v.end(); i++)
    {
        cout << *i<<' ';
    }
    
}

// ==================== 洛谷题目描述 ====================
// 来源：https://www.luogu.com.cn/problem/P1059
//
// # P1059 [NOIP 2006 普及组] 明明的随机数
//
// ## 题目描述
//
// 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了 $N$ 个 $1$ 到 $1000$ 之间的随机整数 $(N\leq100)$，对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
//
// ## 输入格式
//
// 输入有两行，第 $1$ 行为 $1$ 个正整数，表示所生成的随机数的个数 $N$。 第 $2$ 行有 $N$ 个用空格隔开的正整数，为所产生的随机数。
//
// ## 输出格式
//
// 输出也是两行，第 $1$ 行为 $1$ 个正整数 $M$，表示不相同的随机数的个数。 第 $2$ 行为 $M$ 个用空格隔开的正整数，为从小到大排好序的不相同的随机数。
//
// ## 说明/提示
//
// NOIP 2006 普及组 第一题
