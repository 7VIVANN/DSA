#include <iostream>
using namespace std;
// int fact(int n)
// {
//     if (n == 1)
//         return n;
//     else
//     {
//         return n * fact(n - 1);
//     }
// }
// int mxdigits(int n, int max)
// {
//     if (n < 10)
//         return (n > max ? n : max);
//     else
//     {
//         max = max > n % 10 ? max : n % 10;
//         mxdigits(n / 10, max);
//     }
// }
// void pdigits(int n)
// {
//     if (n < 10)
//         cout << n;
//     else
//     {
//         cout << n % 10;
//         pdigits(n / 10);
//         cout << n % 10;
//     }
// }
// int mxarr(int *ar, int n)
// {
//     if (n == 0)
//         return ar[0];
//     else
//     {
//         if (ar[n] > ar[0])
//         {
//             int t = ar[n];
//             ar[n] = ar[0];
//             ar[0] = t;
//         }
//         return mxarr(ar, n - 1);
//     }
// }
// void binary(int n)
// {
//     if (n < 2)
//         cout << n;
//     else
//     {
//         cout << n % 2;
//         binary(n / 2);
//     }
// }
int call(int &p,int &n){
    if(n==0)
        return p;
    else{
        n--;
       return call(p,n );
    }
    
}
int main(){
    int x = 10;
    int y = 10;
    cout<<call(x, y);
}