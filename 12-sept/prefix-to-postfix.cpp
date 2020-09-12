#include <iostream>
#include <string>
using namespace std;
struct stack5
{
    int size;
    int top; //DIAGRAM
    string elements[15];
};

void push5(struct stack5 &s, string x)
{
    if (s.top == s.size - 1)
        cerr << "stack5 overflow ";
    else
        s.elements[++s.top] = x;
}
string pop5(struct stack5 &s)
{
    if (s.top == -1)
        return "";
    else
        return s.elements[s.top--];
}
string peek5(struct stack5 &s)
{
    if (s.top == -1)
        return "";
    else
        return s.elements[s.top];
}
int main()
{
    string pre = "*+AB-+CDEF";
    struct stack5 s;
    s.top = -1;
    s.size = 10;
    for (int i = pre.length()-1; i >= 0; i--)
    {
        char incoming = pre[i];
        int incoming_value = int(incoming);
        if (incoming_value > 64 && incoming_value < 91)
        {
            push5(s, pre.substr(i,1));
        }
        else
        {
            string s1 = pop5(s);
            push5(s, s1 + pop5(s) + incoming);
        } 
    }
   while(peek5(s) != "")
    {
        cout << pop5(s);
    }
}