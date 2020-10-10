#include <iostream>
using namespace std;
void recursive_insert(int *ar, int n, int &i, int &j, int &lower)
{
    if (j == lower)
    {
        i++;
        j = i;
    }
    else
    {
        if (ar[j] < ar[j - 1])
        {
            swap(ar[j], ar[j - 1]);
        }
        j--;
    }
    if (i < n)
        recursive_insert(ar, n, i, j, lower);
}
int main(){
    int n=11;
    int ar[11]={4,2,40,10,10,1,4,2,1,10,40};
    int i =0, j =0 ,lower = 0;
    recursive_insert(ar, n, i, j, lower);
    for (i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    
}