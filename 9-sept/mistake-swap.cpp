#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=6;
    int ar[6]={3,5,9,7,8,6};
    int i = 0;
    int l = 0;
    int h = n - 1;
    while(ar[i]<ar[i+1]){
        l++;
        i++;
    }
    i = h;
    while(ar[i]>ar[i-1]){
        h--;
        i--;
    }
    int t = ar[l];
    ar[l] = ar[h];
    ar[h] = t;
    for (i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    
}