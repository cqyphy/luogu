#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void quick_short(vector<long long>::iterator v,long long len,long long locate){
    if (len <= 1)
    {
        return;
    }
    
    long long i = 0,j = 0,k = len;
    long long pivot = v[rand()%len];
    while (i < k)
    {
        if (v[i] < pivot)
        {
            swap(v[i++],v[j++]);
        }
        else if (v[i] > pivot)
        {
            swap(v[i],v[--k]);
        }
        else i++;        
    }
    quick_short(v,j,locate);
    quick_short(v+k,len - k,locate);
}
int main(){
    long long k,n,temp;
    vector<long long> v;
    scanf("%lld %lld",&n,&k);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&temp);
        v.push_back(temp);
    }
    quick_short(v.begin(),v.size(),k);
    printf("%lld",v[k]);
}