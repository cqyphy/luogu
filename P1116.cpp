#include <iostream>
using namespace std;
int main(){
    int n;
    cin >>n;
    int v[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >>v[i];
    }
    int sum = 0;
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            if (v[i] > v[j])
            {
                sum++;
            }
            
        }
        
    }
    cout << sum;
}