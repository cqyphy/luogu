#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person
{
    string name;
    string type;
    int contribution;
    long level;
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
    if (str == "HuFa")
    {
        return 1;
    }
    if (str == "ZhangLao")
    {
        return 2;
    }
    if (str == "TangZhu")
    {
        return 3;
    }
    if (str == "JingYing")
    {
        return 4;
    }
    if (str == "BangZhong")
    {
        return 5;
    }   
    else return 0;
};
bool contri_sort(const person a,const person b){
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
        v.push_back(p);
    }
    auto it = v.begin()+3;
    if (it == v.end())
    {
        for (auto i = v.begin(); i != v.end(); i++)
        {
            cout << *i;
        }
        return 0;
    }
    stable_sort(it,v.end(),[](const person a,const person b){
            return order(a.type)<order(b.type);
        });
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
    stable_sort(it,v.end(),[](const person a,const person b){
        if (a.type != b.type)
        {
            return order(a.type)<order(b.type);
        }
        return a.level > b.level;
    });
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it);
    }
    
}