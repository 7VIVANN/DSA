#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    char elements[15];
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
char close_index(char c)
{
    char close[5] = {')', '}',']','>','/'};
    for (int i = 0; i < 5; i++)
    {
        if (c == close[i])
            return close[i];
    }
    return '!';
}
char get_corrsponding_open(char c)
{
    char close[5] = {')', '}', ']', '>', '/'};
    char open[5] = {'(', '{', '[', '<', '\\'};
    for (int i = 0; i < 5; i++)
    {
        if (c == close[i])
            return open[i];
    }
    return '!';
}
int find_corresponding_open(char close, stack &s)
{
    //if found pop it off else return -1
    char c = get_corrsponding_open(close);
    struct stack temp;
    temp.size = s.size;
    temp.top = -1;
    while (peek(s) != '!' && peek(s) != c)
    {
        push(temp, pop(s));
    }
    if (peek(s) == c)
    {
        pop(s);
        while (peek(temp) != '!')
        {
            push(s, pop(temp));
        }
        return 1;

    }
    else
    {
        while (peek(temp) != '!')
        {
            push(s, pop(temp));
        }
        return -1;
    }
}
void optimized_reverse(stack &s){
    struct stack temp;
    temp.size = s.size;
    temp.top = -1;
    while(peek(s)!='!'){
        push(temp, pop(s));
    }
    char last_one = peek(temp);
    if (close_index(last_one)=='!')
    {
        push(s, pop(temp));
    }
    push(s, get_corrsponding_open(pop(temp)));
    while(peek(temp)!='!'){
        push(s, pop(temp));
    }
}
int fix(string &x, struct stack &s, int index)
{
    if (index == x.length() - 1)
    {
        return 0;
    }
    char c = x[index];
    if (close_index(c)=='!')
    {
        push(s, c);
    }
    else
    {
        char close = close_index(c);
        int found = find_corresponding_open(close, s);
        if (found== -1)
        {
            char open = get_corrsponding_open(close);
            push(s, open);
            return 1 + fix(x, s, index + 1);
        }
        while (peek(s) != '!')
        {
            pop(s);
        }
    }
    return 0 + fix(x, s, index + 1);
}
int check(int result, string &x, struct stack &s)
{
    if (x.length() == 0)
        return result;
    result += fix(x, s, 0);
    x = "";
    //even after fixing the last string the stack is not empty
    if (peek(s) != '!')
    {
        result++;
        // pop until you find an unmatched open or close symbol and then reverse it
        char close = pop(s);
        push(s, get_corrsponding_open(close));
        // implement such that the last one is reversed if it is a closed one else last but one if it is closed
        // optimized_reverse(s);
    }
    while (peek(s) != '!')
    {
        x = pop(s) + x;
    }
    if (x.length() != 0)
    {
        result += fix(x, s, 0);
    }
    return result;
}
int main()
{
    string brackets = "<<<<<<";
    struct stack s;
    s.top = -1;
    s.size = 15;
    int result;
    result = check(0, brackets, s);
    cout << result;
}
