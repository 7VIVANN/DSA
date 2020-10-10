#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[12];
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

}
int main(){
    struct stack s;
    s.top = -1;
    s.size = 10;
    struct stack temp;
    temp.top = -1;
    temp.size = 10;
}