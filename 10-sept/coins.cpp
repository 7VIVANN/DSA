#include <bits/stdc++.h>
using namespace std;
int coins[] = {10,15};
int solve(int s){
    if(s==0)
        return 0;
    if(s<0)
        return 2147483646 ;
    int x = 2147483646;
    for (auto i : coins)
    {
        x = min(solve(s - i) + 1,x);
    }
    return x;
}
int main(){
    cout << solve(50);
}