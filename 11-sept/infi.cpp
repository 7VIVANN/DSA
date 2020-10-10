#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    char elements[20];
};

void push(struct stack &s, char x)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        s.elements[++s.top] = x;
}
char pop(struct stack &s)
{
    if (s.top == -1)
        return '!';

    else
        return s.elements[s.top--];
}
char peek(struct stack &s)
{
    if (s.top == -1)
        return '!';
    else
        return s.elements[s.top];
}
bool isnum(int val)
{
    return (val < 58 && val > 47) ? true : false;
}
int main()
{
    string exp = "1*7-3-2+8/4";
    cin >> exp;
    struct stack post;
    struct stack exp_stack;
    exp_stack.top = -1;
    exp_stack.size = 15;
    post.top = -1;
    post.size = 15;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        int val = int(c);

        bool incoming_num = isnum(val);

        bool exsiting_num = i == 0 ? true : isnum(peek(exp_stack));
        if (incoming_num)
        {
            push(post,c);
        }
        else if (val == 40)
        {
            push(exp_stack, c);
        }
        else if (peek(exp_stack) == '!')
        {
            push(exp_stack, c);
        }
        else if (peek(exp_stack) != '!')
        {
            while (val <= peek(exp_stack) || int(peek(exp_stack)) == 40)
            {
                push(post, pop(exp_stack));
            }
            push(exp_stack, c);
        }
        else if (val == 41)
        {
            while (peek(exp_stack) != 40)
            {
               push(post,pop(exp_stack));
            }
        }
    }
    while (peek(exp_stack) != '!')
    {
        push(post, pop(exp_stack));
    }
    while (peek(post) != '!')
    {
         pop(post);
    }
   
}