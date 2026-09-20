#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct member
{
    string name;
    int year;
    int month;
    int day;
    int id;
};

int main(){
    int n;
    cin >>n;
    vector<member> v;
    for (size_t i = 0; i < n; i++)
    {
        member tmp;
        cin >>tmp.name>>tmp.year>>tmp.month>>tmp.day;
        tmp.id = i+1;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),[](member a,member b){
        if (a.year == b.year)
        {
            if (a.month == b.month)
            {
                if (a.day == b.day)
                {
                    return a.id > b.id;
                }
                
                return a.day < b.day;
            }            
            return a.month < b.month;
        }
        return a.year < b.year;
    });
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i].name<<endl;
    }
    
}