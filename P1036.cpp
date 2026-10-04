#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int count_ = 0;
vector<int> v;
vector<int> primes;

void sieve(int maxn) {
    vector<bool> is_p(maxn + 1, true);
    is_p[0] = is_p[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (is_p[i]) {
            for (int j = i * i; j <= maxn; j += i)
                is_p[j] = false;
        }
    }
    for (int i = 2; i <= maxn; i++) {
        if (is_p[i]) primes.push_back(i);
    }
}

bool is_prime(long long a) {
    if (a < 2) return false;
    for (int p : primes) {
        if (1LL * p * p > a) return true;   // 用 1LL 防止 p*p 溢出
        if (a % p == 0) return false;
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
    sieve(10000);
    choose_sum(k,0,0);
printf("%d",count_);
}