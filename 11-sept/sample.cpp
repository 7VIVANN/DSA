#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[20];
};

void push(struct stack &s, int x)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        s.elements[++s.top] = x;
}
int pop(struct stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top--];
}
int peek(struct stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top];
}
int n;
int solve(stack &s, int *ar, int i)
{
    if (i == n - 1)
    {
        return 0;
    }
    if (peek(s) < ar[i]&& peek(s)!=-1)
    {
        return -1;
    }
    else
    {
        pop(s);
        push(s, ar[i]);
        solve(s, ar, i + 1);
    }
}
int main()
{

    char c='/';
    cout << c;
}
