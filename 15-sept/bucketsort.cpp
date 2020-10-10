#include <iostream>
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
void stack_sort(struct stack &s, struct stack &temp)
{
    if (peek(s) == -1)
        return;
    int m = pop(s);
    //after this temp is in ascending ordre with largest in m
    while (peek(s) != -1)
    {
        int p = pop(s);
        push(temp, m < p ? m : p);
        m = m > p ? m : p;
    }
    while (peek(temp) != -1)
    {
        push(s, pop(temp));
    }
    stack_sort(s, temp);
    push(temp, m);
}
int main()
{
    int n = 10;
    int ar[n] = {23, 45, 1, 34, 10, 24, 47, 15, 27, 19, 11};
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        max = max > ar[i] ? max : ar[i];
    }
    int k = int(max / n) + 1;
    struct stack s[k];
    for (int i = 0; i < k; i++)
    {
        s[i].top = -1;
        s[i].size = 10;
    }
    for (int i = 0; i < k; i++)
    {
        //scatter the numbers into the range of buckets
        for (int j = 0; j < n; j++)
        {
            int low = i * n;
            int high = (i + 1) * n;
            if (ar[j] >= low && ar[j] <high)
                push(s[i], ar[j]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        //sorting the bucket woth a temporary stack
        struct stack temp;
        temp.top = -1;
        temp.size = 10;
        stack_sort(s[i], temp);
        while (peek(temp) != -1)
            push(s[i], pop(temp));
    }
    
    for (int i = 0; i < k; i++)
    {
        //collecting the from each stack
        while (peek(s[i])!=-1)
        {
            cout << pop(s[i])<<" ";
        }
    }
    

}