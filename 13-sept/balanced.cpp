#include <iostream>
using namespace std;
int find(string &s,int &index,int opened){
    int val = 0;
    while(opened!=0){
        char c = s[index];
        if (c == '(')
        {
            index++;
            val += find(s,index,1);
        }
        if (c == ')')
        {
            index++;
            opened--;
        }
    }
    return val == 0 ? 1 : 2 * val;
}
int main(){
    string s;
    cin >> s;
    int index = 1;
    cout<<find(s, index, 1);
}