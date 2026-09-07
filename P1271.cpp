#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,temp;
    cin >> n>>m;
    vector<int> v1,v2;
    //v1.resize(n);
    v2.resize(n);
    for (size_t i = 0; i < m; i++)
    {
        cin >>temp;
        //v1.push_back(temp);
        v2[temp-1] ++;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < v2[i]; j++)
        {
            cout << i+1<<' ';
        }
        
    }
    
       
}