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
        return s.elements[s.top--];
}
int post_fix_peek(struct post_fix_stack &s)
{
    if (s.top == -1)
        cerr << "post_fix_stack empty ";
    else
        return s.elements[s.top];
}
int main(){
    string s = "12";
    cout << int(s[0]) << " " << s[1];
}