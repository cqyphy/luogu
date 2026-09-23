#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> v = {1,1,1,1,1,1,1,1,1,1} ;
int sum = 0;
vector<vector<int>> vari_v;
void funtion(int n){
    if (n == 0)
    {
        return;
    }
    
    for (size_t i = 9; i >= 0; i--)
    {
        if (v[i]>2)
        {
            continue;
        }        
        v[i]++;
        funtion(n-1);
        if (n - 1 == 0)
        {
            sum ++;
            for (size_t j = 0; j < 10; j++)
            {
                vari_v.push_back(v[j]);
            }            
        }        
        v[i]--;
    }
    
}
int main(){
    int n;
    cin >>n;
    if (n<10 ||n > 30)
    {
        sum = 0;
        cout <<sum;
        return 0;
    }
    funtion(n - 10);
    cout << sum<<endl;
    for (size_t i = 0; i < vari_v.size(); i++)
    {
        if (i+1 % 10 == 0)
        {
            cout <<endl;
        }
        
        cout << v[i]<<' ';
    }
    system("pause");
}