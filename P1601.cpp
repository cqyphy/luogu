#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin >>a>>b;
    int v1[500]= {0},v2[500]= {0};
    for (size_t i = 0; i < a.size(); i++)
    {
        v1[i] = a[a.size()-1-i] - '0';
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        v2[i] = b[b.size()-1-i] - '0';
    }
    int v3[501] = {0},c = 0,temp = 0,side = max(a.size(),b.size());
    for (size_t i = 0; i < side; i++)
    {
        if (i >= a.size() )
        {
            temp = v2[i]+c;
        }
        else if (i >= b.size())
        {
            temp = v1[i]+c;
        }
        else temp = v1[i]+v2[i]+c;
        v3[side -i ] = temp % 10;
        c = temp /10;
    }
    v3[0] += c;
    size_t j = 0;
    if (c == 0)
    {
        j = 1;
    }
    
    for ( j ; j < side+1; j++)
    {
        cout << v3[j];
    }
}

// ==================== 洛谷题目描述 ====================
// 来源：https://www.luogu.com.cn/problem/P1601
//
// # P1601 高精度加法
//
// ## 题目背景
//
// 本题是高精度加法的模板题。
//
// ## 题目描述
//
// 给定两个非负整数 $a,b$，求它们的和。**不用考虑负数**。
//
// ## 输入格式
//
// 输入共两行，每行一个非负整数，分别为 $a,b$。
//
// ## 输出格式
//
// 输出一行一个非负整数，表示 $a+b$ 的值。
//
// ## 说明/提示
//
// 对于 $20\%$ 的测试数据，$a,b \le 10^9$； 对于 $40\%$ 的测试数据，$a,b \le 10^{18}$； 对于 $100\%$ 的测试数据，$0\le a,b \le 10^{500}$。
