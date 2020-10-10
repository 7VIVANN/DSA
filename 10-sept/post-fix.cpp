#include <iostream>
#include <string>
using namespace std;
struct post_fix_stack
{
    int size;
    int top; //DIAGRAM
    int elements[50];
};

void post_fix_push(struct post_fix_stack &s, int x)
{
    if (s.top == s.size - 1)
        cerr << "post_fix_stack overflow ";
    else
        s.elements[++s.top] = x;
}
int post_fix_pop(struct post_fix_stack &s)
{
    if (s.top == -1)
        cerr << "post_fix_stack empty ";
    else
       return  s.elements[s.top--];
}
int post_fix_peek(struct post_fix_stack &s)
{
    if (s.top == -1)
        cerr << "post_fix_stack empty ";
    else
        return s.elements[s.top];
}
//OPERATIONS

int eval(int a, int b, int o)
{
    switch (o)
    {
    case 37:
        return a % b;
    case 42:
        return a * b;
    case 43:
        return a + b;
    case 45:
        return a - b;
    case 47:
        return a / b;
    default:
        break;
    }
}
void postfix(){
    string post = "13452/*-+";
    struct post_fix_stack post_stack;
    post_stack.top = -1;
    post_stack.size = 15;
    for (int i = 0; i < post.length(); i++)
    {
        char c = post[i];
        int val = int(c);
        if (val < 58 && val > 47)
        {
            post_fix_push(post_stack, val-48);
        }
        else
        {
            int operand1 = post_fix_pop(post_stack);
            int operand2 = post_fix_pop(post_stack);
            post_fix_push(post_stack, eval(operand2, operand1, val));
        }
    }
    cout << post_fix_peek(post_stack);
}
int main() { postfix(); }