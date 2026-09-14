#include <iostream>
#include <vector>
using namespace std;
class student
{
private:
public:
    int ch_score,math_score,eng_score,total_score,id;
    student() = default;
    student(int ch,int math,int english):ch_score(ch),math_score(math),eng_score(english){};
    ~student() = default;
    void sum(){total_score = ch_score + math_score + eng_score;}
    friend istream & operator >>(istream &in,student & stu);
    friend ostream & operator << (ostream & out,student & stu);
};

istream & operator >>(istream &in,student & stu){
    in >> stu.ch_score>>stu.math_score>>stu.eng_score;
    stu.sum();
    return in;
}

ostream & operator << (ostream & out,student & stu){
    out << stu.id<<' '<<stu.total_score<<endl;
    return out;
}

void quick_sort_by_id(vector<student>::iterator it,int len){
    if (len <= 1)
    {
        return; 
    }
    int q = 0,w = 0,e = len;
    int pivot = it[rand()% len].id;
    while (q < e)
    {
        if (it[q].id < pivot)
        {
            swap(it[q++],it[w++]);
        }
        else if (it[q].id > pivot)
        {
            swap(it[q],it[--e]);
        }
        else q++;
    }
    quick_sort_by_id(it,w);
    quick_sort_by_id(it+e,len -e);
}

void quick_sort_by_ch_score(vector<student>::iterator it,int len){
    if (len <= 1)
    {
        return; 
    }
    int a = 0,b = 0,c = len;
    int pivot = it[rand()% len].ch_score;
    while (a < c)
    {
        if (it[a].ch_score > pivot)
        {
            swap(it[a++],it[b++]);
        }
        else if (it[a].ch_score < pivot)
        {
            swap(it[a],it[--c]);
        }
        else a++;
    }
    quick_sort_by_ch_score(it,b);
    quick_sort_by_id(it + b,c-b);
    quick_sort_by_ch_score(it+c,len-c);
}

void quick_sort_by_total_score(vector<student>::iterator it,int len){
    if (len <= 1)
    {
        return;
    }
    
    int i = 0,j = 0,k = len;
    int pivot = it[rand()% len].total_score;
    while (i < k)
    {
        if (it[i].total_score > pivot)
        {
            swap(it[i++],it[j++]);
        }
        else if (it[i].total_score < pivot)
        {
            swap(it[i],it[--k]);
        }
        else i++;
    }
    quick_sort_by_total_score(it,j);
    quick_sort_by_ch_score(it + j,k-j);
    quick_sort_by_total_score(it +k,len -k);
    
}

int main(){
    int n = 0;
    vector<student> v;
    cin >>n;
    v.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >>v[i];
        v[i].id = i+1;
    }
    quick_sort_by_total_score(v.begin(),v.size());
    for (size_t i = 0; i < 5; i++)
    {
        cout << v[i];
    }
    //system("pause");
}