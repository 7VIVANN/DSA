#include <iostream>
#include <string>
using namespace std;
struct infix_stack
{
    int size;
    int top; //DIAGRAM
    char elements[50];
};

void infix_push(struct infix_stack &s, char x)
{
    if (s.top == s.size - 1)
        cerr << "infix_stack overflow ";
    else
        s.elements[++s.top] = x;
}
char infix_pop(struct infix_stack &s)
{
    if (s.top == -1)
        return '!';

    else
        return s.elements[s.top--];
}
char infix_peek(struct infix_stack &s)
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
    string post = "";
    struct infix_stack exp_stack;
    exp_stack.top = -1;
    exp_stack.size = 15;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        int val = int(c);

        bool incoming_num = isnum(val);

        bool exsiting_num = i == 0 ? true : isnum(infix_peek(exp_stack));
        if(incoming_num){
            post = post + c;

        }
        else if(val==40){
            infix_push(exp_stack, c);
        }
        else if (infix_peek(exp_stack) == '!')
        {
            infix_push(exp_stack, c);
        }
        else if (infix_peek(exp_stack) != '!')
        {
            while (val <= infix_peek(exp_stack) || int(infix_peek(exp_stack)) == 40)
            {
                post += infix_pop(exp_stack);
            }
            infix_push(exp_stack, c);
        }
        else if (val == 41)
        {
            while (infix_peek(exp_stack) != 40)
            {
                post += infix_pop(exp_stack);
            }
            cout<<infix_pop(exp_stack);
        }
        
    }
    while (infix_peek(exp_stack) != '!')
    {
        post += infix_pop(exp_stack);
    }

    cout << post;
}