#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin >>a>>b;
    int v1[500]= {0},v2[500]= {0};
    for (size_t i = 0; i < a.size(); i++)
    {
        v1[i] = a[a.size()-1-i] - '0';
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        v2[i] = b[b.size()-1-i] - '0';
    }
    int v3[501] = {0},c = 0,temp = 0,side = max(a.size(),b.size());
    for (size_t i = 0; i < side; i++)
    {
        if (i >= a.size() )
        {
            temp = v2[i]+c;
        }
        else if (i >= b.size())
        {
            temp = v1[i]+c;
        }
        else temp = v1[i]+v2[i]+c;
        v3[side -i ] = temp % 10;
        c = temp /10;
    }
    v3[0] += c;
    size_t j = 0;
    if (c == 0)
    {
        j = 1;
    }
    
    for ( j ; j < side+1; j++)
    {
        cout << v3[j];
    }
}