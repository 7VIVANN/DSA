#include <bits/stdc++.h>
using namespace std;
void recursive_insert(int *ar,int n,int &i,int &j,int &lower){
    if(j==lower){
        i++;
        j = i;
    }
    else{
        if(ar[j]<ar[j-1]){
            swap(ar[j], ar[j - 1]);
        }
        j--;
    }
    if(i<n)
    recursive_insert(ar, n, i, j,lower);
}
int main(){
    int a = 15;
    int b = 4;
    int x[15] = {5,8,9,3,5,7,1,3,4,9,3,5,1,8,4};
    int y[4] = {3, 5, 7,2};
    int p = 0;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if(y[i]==x[j]){
                swap(x[p++], x[j]);
            }
        }
    }
    int j = p;
    int k = p;
    recursive_insert(x, a, j, k,p);
    for (int i = 0; i < a; i++)
    {
        cout << x[i] << " ";
    }
    
    
}