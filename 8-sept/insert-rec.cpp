#include <bits/stdc++.h>
using namespace std;
void insert(int *ar,int &n,int &i,int &j){
    if(j==0){
        i++;
        j = i;
    }
    else
    {
        if(ar[j]<ar[j-1]){
            int t = ar[j];
            ar[j] = ar[j - 1];
            ar[j - 1] = t;
            j--;
        }
        else{
            j = 0;
        }
        
    }
    if(i<n)
    insert(ar, n, i, j);
}
int main(){
    int ar[5] = {8,3,7,5,1};
    int n = 5;
    int i = 0;
    int j = 0;
    insert(ar, n, i, j);
    for (int k = 0; k < n; k++)
    {
        cout << ar[k] << " ";
    }
}