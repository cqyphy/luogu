#include <iostream>
using namespace std;
struct Node
{
    int stu_id;
    struct Node* next = nullptr;
    struct Node* prior = nullptr;
    bool is_out = 1;
};
Node* nodes[100005];
void link_node(Node* head,Node* new_node,int id,bool l_or_r){//l_or_r when 0,L   when 0,R
    Node *p = nodes[id];
    if (p->stu_id != id)
    {
        return;
    }
    
    if (!l_or_r)
    {
        new_node->prior = p->prior;
        new_node->next = p;
        p->prior->next = new_node;
        p->prior = new_node;
    }
    else
    {
        new_node->prior = p;
        new_node->next = p->next;
        if (p->next != nullptr)
        {
            p->next->prior = new_node;            
        }        
        p->next =new_node;
    }
}

void delete_node(Node *head,int id){
    Node *p = nodes[id];
    p->is_out = 0;
}

void drop_table(Node *head){
    Node *p = head->next,*pre = head;
    while (p->next != nullptr)
    {
        delete pre;
    }
    delete p;
}

int main(){
    Node* L = new Node;
    L->next = new Node;
    L->next->stu_id = 1;
    L->next->prior = L;
    nodes[1] = L->next;
    L->next->next = nullptr;
    int n,k,p;
    cin >>n;
    for (int i = 0; i < n-1; i++)
    {
        cin >>k>>p;
        Node *s = new Node;
        s->stu_id = i+2;
        nodes[i+2] = s;
        link_node(L,s,k,p);
    }
    int m,del_id;
    cin >>m;
    for (int i = 0; i < m; i++)
    {
        cin >>del_id;
        delete_node(L,del_id);
    }
    Node *find_node = L->next;
    while (find_node != nullptr)
    {
        if (find_node->is_out)
        {            
            cout <<find_node->stu_id<<' ';
        }        
        find_node = find_node->next;
    }
    
}

/*# P1160 队列安排

## 题目描述

一个学校里老师要将班上 $N$ 个同学排成一列，同学被编号为 $1\sim N$，他采取如下的方法：

1. 先将 $1$ 号同学安排进队列，这时队列中只有他一个人；

2. $2\sim N$ 号同学依次入列，编号为 $i$ 的同学入列方式为：老师指定编号为 $i$ 的同学站在编号为 $1\sim(i-1)$ 中某位同学（即之前已经入列的同学）的左边或右边；

3. 从队列中去掉 $M$ 个同学，其他同学位置顺序不变。

在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。

## 输入格式

第一行一个整数 $N$，表示了有 $N$ 个同学。

第 $2\sim N$ 行，第 $i$ 行包含两个整数 $k,p$，其中 $k$ 为小于 $i$ 的正整数，$p$ 为 $0$ 或者 $1$。若 $p$ 为 $0$，则表示将 $i$ 号同学插入到 $k$ 号同学的左边，$p$ 为 $1$ 则表示插入到右边。

第 $N+1$ 行为一个整数 $M$，表示去掉的同学数目。

接下来 $M$ 行，每行一个正整数 $x$，表示将 $x$ 号同学从队列中移去，如果 $x$ 号同学已经不在队列中则忽略这一条指令。

## 输出格式

一行，包含最多 $N$ 个空格隔开的整数，表示了队列从左到右所有同学的编号。

## 输入输出样例 #1

### 输入 #1

```
4
1 0
2 1
1 0
2
3
3
```

### 输出 #1

```
2 4 1
```

## 说明/提示

**【样例解释】**

将同学 $2$ 插入至同学 $1$ 左边，此时队列为：

`2 1`

将同学 $3$ 插入至同学 $2$ 右边，此时队列为：

`2 3 1`  

将同学 $4$ 插入至同学 $1$ 左边，此时队列为：

`2 3 4 1`  

将同学 $3$ 从队列中移出，此时队列为：

`2 4 1`  

同学 $3$ 已经不在队列中，忽略最后一条指令

最终队列：

`2 4 1`  

**【数据范围】**

对于 $20\%$ 的数据，$1\leq N\leq 10$。

对于 $40\%$ 的数据，$1\leq N\leq 1000$。

对于 $100\%$ 的数据，$1<M\leq N\leq 10^5$。*/