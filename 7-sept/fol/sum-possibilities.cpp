#include <iostream>
using namespace std;
string config_first = "";
bool repeated_gen(string a){
    int c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        int x = stoi(a.substr(i, 1));
        if (x == 1)
            c++;
    }
    int n = 0;
    for (int i = 0; i < config_first.length(); i++)
    {
        int x = stoi(config_first.substr(i, 1));
        if (x == c)
            n++;
    }
    if(n==0)
    {
        config_first.append(to_string(c));
        return false;
    }
    else
        return true;
}
void gen(string s)
{
    int n = stoi(s.substr(0,1));
    string b = s.substr(1,s.length()-1);
    for (int i = n-1; i > n / 2-1; i--)
    {
        if(i/2>=0){
            string a = to_string(i) + to_string(n - i)+ b;
            if(repeated_gen(a))
                continue;
            if(stoi(a.substr(0,1))==0)
                continue;
            cout << a<<" ";
            gen(a);
        }
    }
}
int main(){
    int n = 6;
    string s = to_string(n);
    cout << s << " ";
    gen(s);
}