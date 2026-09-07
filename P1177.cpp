#include <iostream>
using namespace std;
template <typename T>
void quick_sort(T arr[],int len){
    if (len <= 1)
    {
        return ;
    }
    const T pivot = arr[rand()%len];
    int i = 0,j = 0,k = len;
    while (i < k)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i++],arr[j++]);
        }
        else if (pivot < arr[i])
        {
            swap(arr[i],arr[--k]);
        }
        else i++;
    }
    quick_sort(arr,j);
    quick_sort(arr+k,len-k);
}
int main(){
    int n;
    cin >>n;
    int v[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >>v[i];
    }
    quick_sort(v,n);
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i]<<' ';
    }
    system("pause");
}