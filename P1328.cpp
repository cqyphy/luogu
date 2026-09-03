#include <iostream>
#include <vector>
using namespace std;
int is_win(int a ,int b){
    if (a == b)
    {
        return 0;
    }
    switch (a)
    {
    case 0:
        if (b == 2 || b == 3)
        {
            return 1;
        }
        return -1;
        break;
    case 1:
        if (b == 0 || b == 3)
        {
            return 1;
        }
        return -1;
        break;
    case 2:
        if (b == 1 || b == 4)
        {
            return 1;
        }
        return -1;
        break;
    case 3:
        if (b == 2 || b == 4)
        {
            return 1;
        }
        return -1;
        break;
    case 4:
        if (b == 0 || b == 1)
        {
            return 1;
        }
        return -1;
        break;
    
    default:
        break;
    }
}

int main(){
    int n,t1,t2;
    cin >>n>>t1>>t2;
    int a_temp[t1],b_temp[t2];
    for (size_t i = 0; i < t1; i++)
    {
        cin >> a_temp[i];
    }
    for (size_t i = 0; i < t2; i++)
    {
        cin >> b_temp[i];
    }
    vector<int> a,b;
    for (size_t i = 0; i < n/t1+1; i++)
    {
        a.insert(a.end(),a_temp,a_temp+t1);
    }
    for (size_t i = 0; i < n/t2+1; i++)
    {
        b.insert(b.end(),b_temp,b_temp+t2);        
    }
    int a_count = 0 ,b_count = 0;
    for (size_t i = 0; i < n; i++)
    {
        int temp_int = is_win(a[i],b[i]);
        if (temp_int == 1)
        {
            a_count += 1;
        }
        else if (temp_int == -1)
        {
            b_count += 1;
        }
        else ;
    }
    cout << a_count <<' '<<b_count;
}