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