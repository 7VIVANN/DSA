#include <iostream>
using namespace std;
int err[] = {-1, -1};
int ar[6][2] = {
    {1, 5},
    {2, 3},
    {4, 6},
    {7, 8},
    {8, 10},
    {12, 15}
};
int n = 6;
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[10][2];
};

void push(struct stack &s, int *a)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
    {
        s.elements[++s.top][0] = a[0];
        s.elements[s.top][1] = a[1];
    }
}
int *pop(struct stack &s)
{
    if (s.top == -1)
        return err;
    else
        return s.elements[s.top--];
}
int *peek(struct stack &s)
{
    if (s.top == -1)
        return err;
    else
        return s.elements[s.top];
}

void solve(int index, struct stack &s)
{
    if(index==n-1){
        return;
    }
    int x = ar[index][0];
    int y = ar[index][1];
    int *ex = peek(s);
    if ((ex[0] < x) && ex[1] < y)
    {
        if (ex[1] > x)
        {
            x = ex[0];
        }
        else if(ex[1]==x)
        {
            pop(s);
            x = ex[0];
        }
        int temp[] = {x, y};
        push(s,temp);
    }
    else if ((ex[0] >= x) && ex[1] >= y)
    {
        pop(s);
        int temp[] = {x, ex[1]};
        push(s, temp);
    }
    else if ((ex[0] <= x) && ex[1] >= y)
    {
        pop(s);
        int temp[] = {ex[0], y};
        push(s, temp);
    }
    solve(index + 1, s);
}
void show(struct stack &s){
    if (peek(s)[0] != -1)
    {
        int *ar = pop(s);
        show(s);
        cout << " {" << ar[0] << "," << ar[1] << "} ";
    }
    else
    {
        return;
    }
    
}
int main()
{
    struct stack s;
    s.top = -1;
    s.size = 10;
    solve(0, s);
    show(s);
}