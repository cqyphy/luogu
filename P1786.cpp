#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person
{
    string name;
    string type;
    long long contribution;
    long level;
    int id;
    //person(string name,string type,long level,int contribution):name(name),type(type),level(level),contribution(contribution) {};

    friend istream & operator >> (istream &in,person &p);
    friend ostream & operator << (ostream &out,person &p);
};

istream & operator >> (istream &in,person &p){
    in >>p.name>>p.type>>p.contribution>>p.level;
    return in;
}

ostream & operator << (ostream &out,person &p){
    out <<p.name<<' '<<p.type<<' '<<p.level<<endl;
    return out;
}
int order( string str){
    if (str == "BangZhu")
    {
        return 1;
    }
    if (str == "FuBangZhu")
    {
        return 2;
    }
    if (str == "HuFa")
    {
        return 3;
    }
    if (str == "ZhangLao")
    {
        return 4;
    }
    if (str == "TangZhu")
    {
        return 5;
    }   
    if (str == "JingYing")
    {
        return 6;
    }   
    if (str == "BangZhong")
    {
        return 7;
    }   
    else return 0;
};
bool contri_sort(const person &a,const person &b){
    if (a.contribution == b.contribution)
    {
        return a.id < b.id;
    }
    
    return a.contribution>b.contribution;
}
int main(){
    int num;
    cin >>num;
    vector<person> v;
    for (size_t i = 0; i < num; i++)
    {
        person p;
        cin >>p;
        p.id = i+1;
        v.push_back(p);
    }
    auto it = v.begin();
    stable_sort(it,v.end(),[](const person &a,const person &b){
        if (order(a.type)==order(b.type))
        {
            if (a.level == b.level)
            {
                return a.id < b.id;
            }
            
            return a.level > b.level;
        }
        
        return order(a.type)<order(b.type);
    });
    it += 3;
    if (it == v.end())
    {
        for (auto i = v.begin(); i != v.end(); i++)
        {
            cout << *i;
        }
        return 0;
    }

    stable_sort(it,v.end(),contri_sort);
    for (size_t i = 0; i < num-3; i++)
    {
        if (i<2)
        {
            (*(it+i)).type = "HuFa";
        }
        else if (i<6)
        {
            (*(it+i)).type = "ZhangLao";
        }
        else if (i<13)
        {
            (*(it+i)).type = "TangZhu";
        }
        else if (i<38)
        {
            (*(it+i)).type = "JingYing";
        }
        else 
        {
            (*(it+i)).type = "BangZhong";
        }
        
    }
    stable_sort(it,v.end(),[](const person &a,const person &b){
        if (order(a.type)==order(b.type))
        {
            if (a.level == b.level)
            {
                return a.id < b.id;
            }
            
            return a.level > b.level;
        }
        
        return order(a.type)<order(b.type);
    });
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it);
    }
    
}

// ==================== 洛谷题目描述 ====================
// 来源：https://www.luogu.com.cn/problem/P1786
//
// # P1786 帮贡排序
//
// ## 题目背景
//
// > 帮派名号：星月家园
// > 帮主尊号：Dragonfly Kang
// > 帮派 ID：2685023
// > 帮派等级：4
// > 帮派人数：101/110
// > 帮派技能：（？）
//
// “星月家园”资料，欢迎各位豆友加入 ^\_^
//
// ---
//
// 在 absi2011 的帮派里，死号偏多。现在 absi2011 和帮主等人联合决定，要清除一些死号，加进一些新号，同时还要鼓励帮贡多的人，对帮派进行一番休整。
//
// ## 题目描述
//
// 目前帮派内共最多有： - $1$ 位帮主（$\texttt{BangZhu}$） - $2$ 位副帮主（$\texttt{FuBangZhu}$） - $2$ 位护法（$\texttt{HuFa}$） - $4$ 位长老（$\texttt{ZhangLao}$） - $7$ 位堂主（$\texttt{TangZhu}$） - $25$ 名精英（$\texttt{JingYing}$） - 若干（数量不限）帮众（$\texttt{BangZhong}$） 保证以上职位是从高到低排列的。 现在 absi2011 要对帮派内几乎所有人的职位全部调整一番。他发现这是个很难的事情。于是要求你帮他调整。 他给你每个人的以下数据： - 名字 - 原来职位 - 帮贡 - 等级 他要按照以下关键字给帮派内的人（帮主、副帮主除外）按以下关键字排序： - 帮贡（从高到低）第一关键字 - 在输入中出现的顺序（从前到后）第二关键字 然后更新这些人的职位： - 第 $1 \sim 2$ 名：护法 - 第 $3 \sim 6$ 名：长老 - 第 $7 \sim 13$ 名：堂主 - 第 $14 \sim 38$ 名：精英 - 第 $39 \sim (n-3)$ 名：帮众 可是，乐斗的显示并不按帮贡排序而按职位和等级排序。 他要你按照以下关键字排序并求出最后乐斗显示的列表（在他调整过职位后）： - 职位（从高到低）第一关键字 - 等级（从高到低）第二关键字 - 在输入中出现的顺序（从前到后）第三关键字 注意：absi2011 无权调整帮主、副帮主的职位，包括他自己的。
//
// ## 输入格式
//
// 第一行一个正整数 $n$，表示星月家园内帮友的人数。 下面 $n$ 行每行两个字符串两个整数，表示每个人的名字、职位、帮贡、等级。
//
// ## 输出格式
//
// 一共输出 $n$ 行，每行包括排序后乐斗显示的名字、职位、等级。
//
// ## 说明/提示
//
// 对于 $10\%$ 的数据，保证 $n=3$。 对于 $40\%$ 的数据，保证各个人的帮贡均为 $0$。 对于 $100\%$ 的数据，保证： - $3\leq n\leq 110$ - $1\leq$ 名字长度 $\leq30$ - 所有名字两两不同 - 名字只包含 ASCII 可见字符 - $0\leq$ 各个人的帮贡 $\leq10^9$ - $1\leq$ 各个人等级 $\leq 150$ - 职位必定为以下七个中的一个： - $\texttt{BangZhu}$ - $\texttt{FuBangZhu}$ - $\texttt{HuFa}$ - $\texttt{ZhangLao}$ - $\texttt{TangZhu}$ - $\texttt{JingYing}$ - $\texttt{BangZhong}$ - 初始时帮派内最多有： - $1$ 位帮主 - $2$ 位副帮主 - $2$ 位护法 - $4$ 位长老 - $7$ 位堂主 - $25$ 名精英 - 恰好有一名帮主 - 恰好有两名副帮主 - 恰好有一名副帮主叫 absi2011 【题目来源】 fight.pet.qq.com absi2011 授权题目
