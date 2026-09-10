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