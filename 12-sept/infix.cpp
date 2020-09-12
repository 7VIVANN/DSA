#include <iostream>
#include <string>
using namespace std;
struct stack1
{
    int size;
    int top; //DIAGRAM
    char elements[20];
};
void push1(struct stack1 &s, char x)
{
    if (s.top == s.size - 1)
        cerr << "stack1 overflow ";
    else
        s.elements[++s.top] = x;
}
char pop1(struct stack1 &s)
{
    if (s.top == -1)
        return '!';
    else
        return s.elements[s.top--];
}
char peek1(struct stack1 &s)
{
    if (s.top == -1)
        return '!';
    else
        return s.elements[s.top];
}
int precedence(char incoming)
{
    switch (incoming)
    {
    case '-':
        return 1;
        break;
    case '+':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '%':
        return 3;
    default:
        return -1;
        break;
    }
}
bool isnum(int val)
{
    return (val < 58 && val > 47) ? true : false;
}
int main()
{
    string actual = "1+3-4*5/2";
    struct stack1 s;
    s.top = -1;
    s.size = 10;
    for (int i = 0; i < actual.length(); i++)
    {
        char incoming = actual[i];
        int incoming_value = int(incoming);
        if (isnum(incoming_value))
        {

            cout << incoming - 48;
        }
        else
        {
            if ((peek1(s) == '!') || (incoming == '(') || ((peek1(s) != '!') && (precedence(incoming) > precedence(peek1(s)))))
                push1(s, incoming);
            else if (incoming == ')')
            {
                while ((peek1(s) != '('))
                {
                    cout << pop1(s);
                }
                pop1(s);
            }
            else
            {
                while ((peek1(s) != '!') && (precedence(incoming) < precedence(peek1(s))))
                {
                    cout << pop1(s);
                }
                push1(s,incoming);
            }
        }
    }
    while (peek1(s) != '!')
    {
        cout << pop1(s);
    }
}