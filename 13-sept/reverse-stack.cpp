#include <iostream>
using namespace std;
//histogram
void histogram()
{
    int n;
    int ar[n];
    int l = ar[0];
    int m = ar[0];
    for (int i = 0; i < n - 1; i++)
    {
        l = ar[i] < ar[i + 1];
        m = m > l ? m : l;
    }
    cout << m;
}
//score
int find(string &s, int &index, int opened)
{
    int val = 0;
    while (opened != 0)
    {
        char c = s[index];
        if (c == '(')
        {
            index++;
            val += find(s, index, 1);
        }
        if (c == ')')
        {
            index++;
            opened--;
        }
    }
    return val == 0 ? 1 : 2 * val;
}
void score()
{
    string s;
    cin >> s;
    int index = 1;
    cout << find(s, index, 1);
}
//window
void window()
{
    int a;
    int A[a];
    int max;
    for (int i = 0; i < a; i++)
    {
        cin >> i;
        if (i == 0)
            max = A[i];
        max = i == 0 ? A[i] : max > A[i] ? max : A[i];
    }
    int B;
    cin >> B;
    if (B > a)
    {
        cout << max;
    }
    else
    {
        int C[a - B + 1];
        for (int i = 0; i < a; i++)
        {
            int x = i + B;
            if (x == a)
                break;
            max = A[i];
            for (int j = i; j < x; j++)
            {
                max = max > A[i] ? max : A[i];
            }
            C[i] = max;
        }
        for (auto &&i : C)
        {
            cout << i << " ";
        }
    }
}
//reverse-stack
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[50];
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
void rev(stack &s)
{
    if (peek(s) != -1)
    {
        int x = pop(s);
        rev(s);
        push(s, x);
    }
    else
    {
        return;
    }
    
}
void stack_reverse()
{
    struct stack s;
    s.top = -1;
    s.size = 5;
    for (int i = 0; i < 5; i++)
    {
        push(s, i);
    }
    while (peek(s) != -1)
    {
        cout << peek(s) << " ";
    }

    rev(s);
    while (peek(s) != -1)
    {
        cout << peek(s) << " ";
    }
}
int main()
{
    cout << "histogram: enter number of elements and then the elements";
    histogram();
    cout << endl;
    cout << "stack reverse:";
    stack_reverse();
    cout << endl;
    cout << "window :enter size of A ,elements of A,B ";
    window();
    cout << endl;
    cout << "balanced-parentheses : enter string";
    score();
    cout << endl;
}
