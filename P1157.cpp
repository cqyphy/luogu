#include <iostream>
#include <iomanip>
using namespace std;
int n,r;
int a[20];
void dfs(int step,int start){
    if (step == r)
    {
        for (size_t j = 0; j < step; j++)
        {
            cout <<setw(3)<<a[j];
        }
        cout <<endl;
        return;
    }
    
    for (size_t i = start; i < n+1; i++)
    {
        a[step] = i;
        dfs(step + 1,i+1);
    }
    
}
int main(){
    cin >>n>>r;
    dfs(0,1);
    //system("pause");
}