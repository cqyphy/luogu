#include <iostream>
#include <vector>
using namespace std;
struct three_num
{
    int num1 = 0,num2 = 0,num3 = 0;
    // friend three_num operator/(const three_num& a,const three_num& b){
    //     three_num tmp;
    //     tmp.num1 = a.num1 / b.num1;
    //     tmp.num2 = a.num2 / b.num2;
    //     tmp.num3 = a.num3 / b.num3;
    //     return tmp;
    // }
};
vector<int> all_nums;
vector<three_num> v;
void make_nums(){
    for (size_t i = 1; i < 10; i++)
    {
        for (size_t j = 1; j < 10; j++)
        {
            if (j == i)
            {
                continue;
            }
            for (size_t k = 1; k < 10; k++)
            {
                if (k == j || k == i)
                {
                    continue;
                }
                for (size_t q = 1; q < 10; q++)
                {
                    if (q == i || q == j || q == k)
                    {
                        continue;
                    }
                    for (size_t w = 1; w < 10; w++)
                    {
                        if (w == i || w == j || w == k ||w == q)
                        {
                            continue;
                        }
                        for (size_t e = 1; e < 10; e++)
                        {
                            if (e == i || e == j || e == k ||e == q || e == w)
                            {
                                continue;
                            }
                            for (size_t r = 1; r < 10; r++)
                            {
                                if (r == i || r == j || r == k ||r == q || r == w || r == e)
                                {
                                    continue;
                                }
                                for (size_t t = 1; t < 10; t++)
                                {
                                    if (t == i || t == j || t == k ||t == q || t == w || t == e || t == r)
                                    {
                                        continue;
                                    }
                                    for (size_t y = 1; y < 10; y++)
                                    {
                                        if (y == i || y == j || y == k ||y == q || y == w || y == e || y == r || y == t)
                                        {
                                            continue;
                                        }
                                        three_num tmp;
                                        tmp.num1 = k+j*10+i*100;
                                        tmp.num2 = e+w*10+q*100;
                                        tmp.num3 = y+t*10+r*100;
                                        v.push_back(tmp);
                                    }
                                }
                            }
                        }
                    }
                    
                }
                
            }
        }
        
    }
}

// void put_nums(){
//     for (auto i = all_nums.begin(); i != all_nums.end(); i++)
//     {
//         three_num tmp;
//         for (auto j = i+1; j != all_nums.end(); j++)
//         {
//             for (auto k = j+1; k != all_nums.end(); k++)
//             {
//                 tmp.num1 = *i;
//                 tmp.num2 = *j;
//                 tmp.num3 = *k;
//                 v.push_back(tmp);//有问题
//             }
            
//         }
//     }
    
//}
int main(){
    make_nums();
    //put_nums();
    three_num base;
    cin >>base.num1>>base.num2>>base.num3;
    if (base.num1 == 0 )
    {
        cout <<"No!!!";
        return 0;
    }
    
    three_num count_ ;
    bool exist = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i].num1 * base.num2 == v[i].num2 * base.num1 && v[i].num2 * base.num3 == v[i].num3 * base.num2)
        {
            cout <<v[i].num1<<' '<<v[i].num2<<' '<<v[i].num3<<endl;
            exist = 1;
        }
    }
    if (!exist)
    {
        cout <<"No!!!";
    }
    
    system("pause");
}


/*# P1618 三连击（升级版）

## 题目描述

将 $1, 2,\ldots, 9$ 共 $9$ 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 $A:B:C$，试求出所有满足条件的三个三位数，若无解，输出 `No!!!`。

## 输入格式

三个数，$A,B,C$。

## 输出格式

若干行，每行 $3$ 个数字。按照每行第一个数字升序排列。

## 输入输出样例 #1

### 输入 #1

```
1 2 3
```

### 输出 #1

```
192 384 576
219 438 657
273 546 819
327 654 981
```

## 说明/提示

保证 $0 \le A<B<C \le 999$。

---

$\text{upd 2022.8.3}$：新增加二组 Hack 数据。*/