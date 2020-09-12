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
int fix(string &x,struct stack &s,int index){
    if(index==x.length()-1){
        return 0;
    }
    char c = x[index];
    if(c=='{'){
        push(s, c);
        
    }
    else
    {
        if(peek(s)=='!'){
            pop(s);
            push(s,'{');
            return 1 + fix(x, s, index + 1);
        }
        while (peek(s)!='!')
        {
            pop(s);
            
        } 
    }
    return 0+fix(x,s,index+1);
}
int check(int result, string &x, struct stack &s)
{
    if(x.length()==0)
        return result;
    result += fix(x, s, 0);
    x = "";
    if (peek(s) != '!')
    {
        result++;
        pop(s);
        push(s,'}');
    }
    while (peek(s) != '!')
    {
        x = pop(s) + x;
        // result++;
    }
    if(x.length()!=0){
        result += fix(x, s, 0);
    }
    return result;
}
int main(){
    string brackets = "}{";
    struct stack s;
    s.top = -1;
    s.size = 15;
    int result;
    result = check(0, brackets, s);
    cout << result;
}