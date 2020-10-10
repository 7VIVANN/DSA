#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
int main()
{
    int a = 5;
    int b = 3;
    int x[5]={1,4,7,8,10};
    int y[3] = {2, 3, 9};
    for (int i = 0; i < a; i++)
    {
        if(x[i]>y[0]){
            swap(x[i], y[0]);
            int j = 1;
            while (j<b && y[0]>=y[j])
            {
                j++;
            }
            int k = 0;
            while(j>1)
            {
                swap(y[k], y[k + 1]);
                k++;
                j--;
            } 
        }
    }
    for (int i = 0; i < a; i++)
    {
        cout << x[i] << " ";
    }
    for (int i = 0; i < b; i++)
    {
        cout << y[i] << " ";
    }
}