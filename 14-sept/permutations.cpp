#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}
void permute(int *ar,int index,int n){
    if(index==n){
        return;
    }
    else
    {
        for (int i = index; i < n; i++)
        {
            swap(ar[index], ar[i]);
            cout <<ar[i];
            permute(ar, index + 1, n);
            if(n==i-1)
                cout <<"\t";
            swap(ar[index], ar[i]);
        }
        cout << endl;
    }
}
int main(){
    int n = 3;
    int ar[n]={1,2,3};
    permute(ar, 0, n);
}