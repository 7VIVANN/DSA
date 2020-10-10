#include <iostream>
#include <string>
using namespace std;
int k,n;
string fib(string F0,string F1,int &x){
    if(x==n)
        return F1;
    else
    {
        x++;
        return fib(F1, F0 + F1, x);
    }
}
int main(){
    string f0="a",f1="bc";
    int x = 1;
    cin >> n >> k;
    cout << fib(f0, f1, x)[k];
}