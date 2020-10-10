#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    int ar[8]={1,3,2,7,5,6,4,8};
    int l=0;
    int h=n-1;
    int i = 0;
    while(i<n && ar[i]<ar[i+1] )
    {
        l = ++i;
    }
    i = n - 1;
    while (i > l+1 && ar[i] > ar[i - 1])
    {
        h = --i;
    }
    cout << l << " " << h;
}