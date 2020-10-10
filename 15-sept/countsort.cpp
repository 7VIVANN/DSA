#include <iostream>
using namespace std;
void cosort(int *ar,int *tag,int *b,int *ctag,int n){
    
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        max = max > ar[i] ? max : ar[i];
    }
    max++;
    // count the frequency of ar[]
    int fr[max];
    for (int i = 0; i < max; i++)
    {
        fr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        fr[ar[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        cout << fr[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i < max; i++)
    {
        fr[i] += fr[i - 1];
    }
    for (int i = 0; i < max; i++)
    {
        cout << fr[i] << " ";
    }
    cout << "\n";
   
    for (int i = n-1; i >=0 ; i--)
    {
        int pos = fr[ar[i]];
        if (pos > 0)
        {
            b[pos-1] = ar[i];
            ctag[pos-1] = tag[i];
            fr[ar[i]] = fr[ar[i]] - 1;
            ;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ctag[i] << " ";
    }
}
int main()
{
    int n = 11;
    int ar[11] = {0, 12, 0, 8, 7, 12, 0, 4, 0, 2, 1};
    int tag[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[n];
    int ctag[n];
    cosort(ar,tag,b,ctag,n);
}