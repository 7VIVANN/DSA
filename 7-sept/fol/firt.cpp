#include <iostream>
using namespace std;
void bubble(int &i,int &j,int *ar,int n){
    if(j==n-1){
        i += 1;
        j = i;
    }
    else{
        
        if(ar[j]<ar[j+1]){
            int t = ar[j];
            ar[j] = ar[j + 1];
            ar[j + 1] = t;
        }
        j += 1;
        bubble(i, j, ar, n);
    }
    
}

void select(int sm,int &i,int &j,int *ar,int &n){
    if(j==n-1)
    {
        int t = ar[i];
        ar[i] =  sm;
        sm = t;
        j = 0;
        i += 1;
    }
    else{
        sm = sm < ar[j] ? sm : ar[j];
        j += 1;
        select(sm,i,j,ar,n);
    }
}
int main(){
    int n = 6;
    int ar[6];
    int br[6];
    for (int i = 0; i < n/2; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        cin >> br[i];
    }
    int i = 0;
    int j = 0;
    select(ar[0], i, j, ar, n/2);
    i = 0;
    j = 0;
    bubble(i, j, ar, n/2);
    for (auto &&k : ar)
    {
        cout << k;
    }
    for (auto &&k : br)
    {
        cout << k;
    }
    // int ar[4] = {1, 5, 7,3};
    // int i = 0;
    // int j = 0;
    // int n = 4;
    // bubble(i, j, ar,n);
    // for (auto &&i : ar)
    // {
    //     cout << i;
    // }
    
}