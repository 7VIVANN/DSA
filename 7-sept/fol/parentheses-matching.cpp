#include <bits/stdc++.h>
using namespace std;
//con : no of ones is even
string config_third="";
bool repeated_fix(string cn){

    int len = config_third.length();
    int l = cn.length();
    int begin = 0;
    int counter = 0;
    while (begin < len)
    {
        if (config_third.substr(begin, l).compare(cn) == 0)
        {
            counter++;
            break;
        }
        begin += l;
    }
    if (counter == 0)
    {
        config_third.append(cn);
        return false;
    }
    else
        return true;
}
void fix(char *word, int *tag, int n, int &number, int initial)
{   
    if(number==2*n){
        string cn = "";
        for (int i = 0; i < 2*n; i++)
        {   
            cn.append(1,word[i]);
        }
        if(!repeated_fix(cn))
            cout << cn << " ";
    }
    
    for (int i = initial; i <  2*n; i++)
    {
        if (tag[i] == 0)
        {
            tag[i] = 1;
            word[i] = number%2==0 ? '(' : ')';
            number++;
            if(number%2!=0)
                fix(word, tag, n, number,i+1);
            else
                fix(word, tag, n, number, 0);

            tag[i] = 0;
            number--;

        }
    }
}
int main(){
    int n = 3;
    char word[2 * n];
    int tag[2 * n];
    for (int i = 0; i < 2*n; i++)
    {
        tag[i] = 0;
    }
    word[0] = '(';
    tag[0] = 1;

    int number = 1;
    fix(word,tag,n,number,1);
}