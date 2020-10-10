#include <iostream>
using namespace std;
int mxarr(int *ar, int n)
{
    if (n == 0)
        return ar[0];
    else
    {
        if (ar[n] > ar[0])
        {
            int t = ar[n];
            ar[n] = ar[0];
            ar[0] = t;
        }
        return mxarr(ar, n - 1);
    }
}
int mnarr(int *ar, int n)
{
    if (n == 0)
        return ar[0];
    else
    {
        if (ar[n] < ar[0])
        {
            int t = ar[n];
            ar[n] = ar[0];
            ar[0] = t;
        }
        return mnarr(ar, n - 1);
    }
}
int smarr(int *ar,int n){
    if (n == 0)
        return ar[0];
    else{
        ar[0] += ar[n];
        smarr(ar, n - 1);
    }
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    cout<<"min" << mnarr(arr, 5)<<endl;

    cout<<"max" << mxarr(arr, 5)<<endl;

    cout<<"average" << smarr(arr, 5)/5<<endl;
}