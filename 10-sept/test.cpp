#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[20][2];
};

void push(struct stack &s, int *x)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
     {   s.elements[++s.top][0] =x[0];
         s.elements[s.top][1] = x[1];
     }
}
int* pop(struct stack &s)
{
    if (s.top == -1)
        cerr << "stack empty ";
    else
        return s.elements[s.top--];
}
int* peek(struct stack &s)
{
    if (s.top == -1)
        cerr << "stack empty ";
    else
        return s.elements[s.top];
}

int main(){
    char x[] = "{{}}";
    string s="{{}}";

    cout << s.compare(x);
}