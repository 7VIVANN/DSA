#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int ar[n];
    for (auto &&i : ar)
    {
        cin >> i;
    }

    int l=ar[0];
    int m=ar[0]<ar[1]?ar[0]:ar[1];
    for (int i = 1; i < n-1; i++)
    {
        l = ar[i] < ar[i + 1]?ar[i]:ar[i+1];
        m = m > l ? m : l;
    }
    cout << m;
}