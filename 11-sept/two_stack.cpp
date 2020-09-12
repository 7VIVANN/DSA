#include <iostream>
#include <string>
using namespace std;
struct stack1
{
    int size;
    int top; //DIAGRAM
};

void push(struct stack &s, int x,int *ar)
{
    s.size++;
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        ar[++s.top] = x;
}
int pop(struct stack &s,int *ar)
{
    if (s.top == -1)
        return -1;
    s.size--;
    else
        return ar[s.top--];
}
int peek(struct stack &s,int *ar)
{
    if (s.top == -1)
        return -1;
    else
        return ar[s.top];
}
struct stack1
{
    int size;
    int top; //DIAGRAM
};

void push(struct stack &s, int x, int *ar)
{
    s.size++;
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        ar[--s.top] = x;
}
int pop(struct stack &s, int *ar)
{
    if (s.top == -1)
        return -1;
    s.size--;
    else return ar[s.top++];
}
int peek(struct stack &s, int *ar)
{
    if (s.top == -1)
        return -1;
    else
        return ar[s.top];
}
int main(){
    int n = 11;
    int ar[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    struct stack s1;
    struct stack s2;
    while(s1.top!=s2.top){
        int a, b, c;
        cin >> a >> b >> c;
        switch (c)
        {
        case 1:
            push(s1, b,ar);
            break;
        case -1:
            cout<<pop(s1,ar);
            break;
        case 0:
            cout<<peek(s1,ar);
            break;
        }
    }
}