#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s1;
    stack<int> s2;
    int n = 5;
    int ar[n] = {1, 2, 3, 4, 5};
    for (int i = 0; i < n; i++)
    {
        if(s1.size==0){
            s1.push(ar[i]);
        }
    }
    
}