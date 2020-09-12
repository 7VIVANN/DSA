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

struct string_stack
{
    int size;
    int top; //DIAGRAM
    string elements[15];
};
void string_push(struct string_stack &s, string x)
{
    if (s.top == s.size - 1)
        cerr << "string_stack overflow ";
    else
        s.elements[++s.top] = x;
}
string string_pop(struct string_stack &s)
{
    if (s.top == -1)
        return "";
    else
        return s.elements[s.top--];
}
string string_peek(struct string_stack &s)
{
    if (s.top == -1)
        return "";
    else
        return s.elements[s.top];
}

int precedence(char incoming)
{
    switch (incoming)
    {
    case '-':
        return 1;
        break;
    case '+':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '%':
        return 3;
    default:
        return -1;
        break;
    }
}
bool isnum(int val)
{
    return (val < 58 && val > 47) ? true : false;
}
string rev_infix(string &x)
{
    string fin = "";
    for (int i = x.length() - 1; i >= 0; i--)
    {
        char c = x[i];
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
        fin += c;
    }
    return fin;
}
string in_to_po(struct stack &s, string actual)
{
    string fin = "";
    for (int i = 0; i < actual.length(); i++)
    {
        char incoming = actual[i];
        int incoming_value = int(incoming);
        if (isnum(incoming_value))
        {
            fin+= incoming;
        }
        else
        {
            if ((peek(s) == '!') || (incoming == '(') || ((peek(s) != '!') && (precedence(incoming) > precedence(peek(s)))))
                push(s, incoming);
            else if (incoming == ')')
            {
                while ((peek(s) != '('))
                {
                    fin+= pop(s);
                }
                pop(s);
            }
            else
            {
                while ((peek(s) != '!') && (precedence(incoming) <= precedence(peek(s))))
                {
                    fin+=pop(s);
                }
                push(s, incoming);
            }
        }
    }
    while (peek(s) != '!')
    {
        fin+= pop(s);
    }
    return fin;
}
string in_to_pre(struct stack &s, string actual)
{
    actual = rev_infix(actual);
    actual = in_to_po(s, actual);
    string final = "";
    for (int i = 0; i < actual.length(); i++)
    {
        final = actual[i] + final;
    }
    return final;
}

string po_to_in(struct string_stack &s,string post)
{
    for (int i =0; i <post.length() ; i++)
    {
        char incoming = post[i];
        int incoming_value = int(incoming);
        if (incoming_value > 47 && incoming_value < 58)
        {
            string_push(s, post.substr(i, 1));
        }
        else
        {
            string s1 = string_pop(s);
            string fin = "(" + s1 + incoming + string_pop(s) + ")";
            string_push(s,fin);
        }
    }
    string stitch = "";
    while(string_peek(s)!=""){
        stitch += string_pop(s);
    }
    return stitch;
}
string po_to_pre(struct string_stack &s, string post)
{
    for (int i =0; i <post.length(); i++)
    {
        char incoming = post[i];
        int incoming_value = int(incoming);
        if (incoming_value > 47 && incoming_value < 58)
        {
            string_push(s, post.substr(i, 1));
        }
        else
        {
            string s1 = string_pop(s);
            string fin =  incoming + string_pop(s) + s1;
            string_push(s, fin);
        }
    }
    string stitch="";
    while(string_peek(s)!=""){
        stitch += string_pop(s);
    }
    return stitch;
}
string pre_to_in(struct string_stack &s,string pre){
    string fin = "";
    for (int i = 0; i < pre.length(); i++)
    {
        fin = pre[i] + fin;
    }
    return po_to_in(s,fin);

}
string pre_to_po(struct string_stack &s ,string pre)
{
    for (int i = pre.length() - 1; i >= 0; i--)
    {
        char incoming = pre[i];
        int incoming_value = int(incoming);
        if (incoming_value > 47 && incoming_value < 58)
        {
            string_push(s, pre.substr(i, 1));
        }
        else
        {
            string s1 = string_pop(s);
            string_push(s, s1 + string_pop(s) + incoming);
        }
    }
    string fin = "";
    while (string_peek(s) != "")
    {
        fin += string_pop(s);
    }
    return fin;
}

void driver(){
    string statement = "1. Infix to prefix\n2. Infix to postfix\n3.  Prefix to infix\n4. Prefix to postfix\n 5. Postfix to infix\n6.  Post fix to prefix.\n";
    cout << statement;

    int option;
    cin >> option;

    string expression;
    cin >> expression;

    struct stack s1;
    s1.top = -1;
    s1.size = 15;

    struct string_stack s2;
    s2.top = -1;
    s2.size = 15;

    switch (option)
    {
    case 1:
        cout<<in_to_pre(s1, expression)<<endl;
        break;
    case 2:
        cout << in_to_po(s1, expression)<<endl;
        break;
    case 3:
        cout << pre_to_in(s2, expression)<<endl;
        break;
    case 4:
        cout << pre_to_po(s2, expression)<<endl;
        break;
    case 5:
        cout << po_to_in(s2, expression)<<endl;
        break;
    case 6:
        cout << po_to_pre(s2, expression)<<endl;
        break;
    default:
        return;
        break;
    }
    driver();
}

int main()
{
    driver();
}