#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int count_ = 0;
vector<int> v;
bool is_prime(int a){
    if (a <= 1 )
    {
        return false;
    }
    if (a == 2)
    {
        return true;
    }
    if (a%2 == 0)
    {
        return false;
    }
    
    for (size_t i = 3; i*i <= a; i += 2)
    {
        if (a % i == 0)
        {
            return false;
        }
        
    }
    return true;
}
void choose_sum (int k,size_t index,int sum){
    if (k == 0)
    {
        if (is_prime(sum))
        {
            count_ ++;
        }
        
        return;
    }
    
    for (size_t i = index; i <= v.size() - k; i++)
    {
        choose_sum(k-1,i+1,sum + v[i]);
    }

}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for (size_t i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    choose_sum(k,0,0);
printf("%d",count_);
}