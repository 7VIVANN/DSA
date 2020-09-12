#include <iostream>
using namespace std;
int eval(int a, int b, int o)
{
    switch (o)
    {
    case 37:
        return a % b;
    case 42:
        return a * b;
    case 43:
        return a + b;
    case 45:
        return a - b;
    case 47:
        return a / b;
    default:
        break;
    }
}
int solve4(string &x,int &index,int a,int b){
    if(index==x.length()){
        return b;
    }
    char incoming = x[index];
    int incoming_value = int(incoming);
    if(incoming_value>47&&incoming_value<58){
        index++;
        b=solve4(x, index, b, incoming_value-48);
        index++;
        return solve4(x,index, a,b );
    }
    else
    {
        return eval(a,b,incoming_value);
    }    
}
int main(){
    string value = "13452/*-+";
    int index = 2;
    int result = solve4(value, index, stoi(value.substr(0, 1)), stoi(value.substr(1, 1)));
    cout << result;
}