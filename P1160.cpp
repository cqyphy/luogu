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