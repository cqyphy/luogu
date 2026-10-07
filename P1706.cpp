#include <iostream>
#include <iomanip>
using namespace std;
int n;
int a[10];
void dfs(int step){
    if (step == n)
    {
        for (size_t j = 0; j < step; j++)
        {
            cout <<setw(5)<<a[j];
        }
        cout <<endl;
        return;
    }
    
    for (size_t i = 1; i < n+1; i++)
    {
        bool bool_a = 0;
        for (size_t k = 0; k < step; k++)
        {
            if (i == a[k])
            {
                bool_a = 1;
                break;
            }
            
        }
        if (bool_a)
        {
            continue;
        }
        
        a[step] = i;
        dfs(step + 1);
    }
    
}
int main(){
    cin >>n;
    dfs(0);
    //system("pause");
}