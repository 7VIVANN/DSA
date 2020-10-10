#include <iostream>
#include <string>
using namespace std;
//first
string config_first = "";
bool repeated_gen(string a)
{
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
    if (n == 0)
    {
        config_first.append(to_string(c));
        return false;
    }
    else
        return true;
}
void gen(string s)
{
    int n = stoi(s.substr(0, 1));
    string b = s.substr(1, s.length() - 1);
    for (int i = n - 1; i > n / 2 - 1; i--)
    {
        if (i / 2 >= 0)
        {
            string a = to_string(i) + to_string(n - i) + b;
            if (repeated_gen(a))
                continue;
            if (stoi(a.substr(0, 1)) == 0)
                continue;
            cout << a << " ";
            gen(a);
        }
    }
}
void first()
{
    int n = 4;
    //cin>>n;
    string s = to_string(n);
    cout << s << " ";
    gen(s);
}
//second
bool match(int &start, int &len, string &s, string &str)
{
    if (start == str.length())
    {
        return false;
    }
    string subs = str.substr(start, len);
    if (subs.compare(s) == 0)
        return true;
    else
    {
        start += 1;
        return match(start, len, s, str);
    }
}
void second()
{
    string str = "cathartic";
    string s = "har";
    //cin>>str>>s;
    int start = 0;
    int len = s.length();
    string r = match(start, len, s, str) == true ? "true" : "false";
    cout << r;
}
//third
string config_third = "";
bool repeated_fix(string cn)
{

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
    if (number == 2 * n)
    {
        string cn = "";
        for (int i = 0; i < 2 * n; i++)
        {
            cn.append(1, word[i]);
        }
        if (!repeated_fix(cn))
            cout << cn << " ";
    }

    for (int i = initial; i < 2 * n; i++)
    {
        if (tag[i] == 0)
        {
            tag[i] = 1;
            word[i] = number % 2 == 0 ? '(' : ')';
            number++;
            if (number % 2 != 0)
                fix(word, tag, n, number, i + 1);
            else
                fix(word, tag, n, number, 0);

            tag[i] = 0;
            number--;
        }
    }
}
void third()
{
    int n = 3;
    //cin >> n;
    char word[2 * n];
    int tag[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        tag[i] = 0;
    }
    word[0] = '(';
    tag[0] = 1;

    int number = 1;
    fix(word, tag, n, number, 1);
}
//fourth
string fib(string F0, string F1, int &x,int &n)
{
    if (x == n)
        return F1;
    else
    {
        x++;
        return fib(F1, F0 + F1, x,n);
    }
}
void fourth()
{
    string f0 = "a", f1 = "bc";
    int x = 1;
    int n,k;
    n = 4;
    k = 3;
    // cin >> n >> k;
    cout << fib(f0, f1, x, n)[k];
}

int main()
{
    first();
    second();
    third();
    fourth();
}
