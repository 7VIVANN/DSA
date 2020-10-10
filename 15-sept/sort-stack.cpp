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
void sort(struct stack &s,struct stack &temp){
    if(peek(s)==-1)
        return;
    int m = pop(s);
    while (peek(s) != -1)
    {
        int p = pop(s);
        push(temp, m > p ? m : p);
        m = m < p ? m : p;
    }
    while (peek(temp) != -1)
    {
        push(s, pop(temp));
    }
    sort(s,temp);
    push(temp, m);
}
int main(){
    struct stack s;
    s.top = -1;
    s.size = 10;
    push(s, 13);
    push(s, 3);
    push(s, 4);
    push(s, 1);
    push(s, 10);
    push(s, 6);
    push(s, 2);
//13 3 4 1 10 6 2
    struct stack temp;
    temp.top = -1;
    temp.size = 10;
    int m = pop(s);
    //collect them from the stack
    //after sorting them

    sort(s, temp);
    
    while(peek(temp)!=-1){
        cout << pop(temp)<<" ";
    }
}