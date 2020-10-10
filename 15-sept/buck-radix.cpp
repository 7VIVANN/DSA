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
int get_n_digit(int x,int n){
    while (x>1)
    {
        x--;
        n /= 10;
    }
    return n % 10;
}
int main(){
    int n=10;
    int ar[n] = {23, 45, 1, 34, 10, 24, 47, 15, 27, 19};

    struct stack radstack[10];
    for (int i = 0; i < 10; i++)
    {
        radstack[i].top = -1;
        radstack[i].size = 10;
    }
    //divide by radix 10
    for (int i = 0; i < n; i++)
    {
        int di = get_n_digit(1, ar[i]);
        push(radstack[di], ar[i]);

    }
    //radstack 10
    int counter = 2;
    int digit = 2;
    while (counter!=1)
    {
        counter = 0;
        for (int i = 0; i < 10; i++)
        {
            while (peek(radstack[i]) != -1)
            {
                int num = pop(radstack[i]);
                int di = get_n_digit(digit, num);
                push(radstack[di], num);
                counter++;
            }
        }
       digit++;
    }
    
}