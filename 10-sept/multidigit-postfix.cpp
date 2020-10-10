#include <iostream>
#include <string>
using namespace std;
struct multi_postfix_stack
{
    int size;
    int top; //DIAGRAM
    string elements[50];
};
void multi_postfix_push(struct multi_postfix_stack &s, string x)
{
    if (s.top == s.size - 1)
        cerr << "multi_postfix_stack overflow ";
    else
        s.elements[++s.top] = x;
}
string multi_postfix_pop(struct multi_postfix_stack &s)
{
    if (s.top == -1)
        return "";
    else
       return  s.elements[s.top--];
}
string multi_postfix_peek(struct multi_postfix_stack &s)
{
    if (s.top == -1)
        return "";
    else
        return s.elements[s.top];
}
int extractor(string sentence,multi_postfix_stack &s,string *post){
    string word = "";
    char c[] = " ";
    int begin = 0;
    int end = 1;
    int pos = 0;
    while (sentence.find(c, begin) != string::npos)
    {
        end = sentence.find(c, begin);
        word = sentence.substr(begin, end - begin);
        post[pos++] = word;
        begin = end + 1;
    }
    post[pos++]=(s,sentence.substr(end + 1, sentence.length() - end));
    return pos;
}
bool isnum(string x){
    int c = int(x[0]);
    return (c > 48 && c < 57) ? true : false;
}
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
        return 0;
    }
}
int main(){
    struct multi_postfix_stack s;
    string post[20];
    int count=extractor("11 12 13 * + 15 -", s, post);
    for (int i = 0; i < count; i++)
    {
        string incoming_string = post[i];
        bool incoming_num = isnum(incoming_string);
        if(incoming_num){
            multi_postfix_push(s, incoming_string);
        }
        else
        {
            int op1 = stoi(multi_postfix_pop(s));
            int op2 = stoi(multi_postfix_pop(s));
            int oprtr = int(incoming_string[0]);
            multi_postfix_push(s,to_string(eval(op2, op1, oprtr)));
        }
    }  
    while(multi_postfix_peek(s)!=""){
        cout << multi_postfix_pop(s);
    }
}