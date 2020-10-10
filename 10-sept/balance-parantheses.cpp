#include <iostream>
#include <string>
using namespace std;
struct balance_stack
{
    int size;
    int top; //DIAGRAM
    char elements[50];
};

void balance_push(struct balance_stack &s, char x)
{
    if (s.top == s.size - 1)
        cerr << "balance_stack overflow ";
    else
        s.elements[++s.top] = x;
}
char balance_pop(struct balance_stack &s)
{
    if (s.top == -1)
        cerr << "balance_stack empty ";
    else
        return s.elements[s.top--];
}
char balance_peek(struct balance_stack &s)
{
    if (s.top == -1)
        return '!';
    else
        return s.elements[s.top];
}
string final_string = "";
void string_formation(struct balance_stack &s)
{
    char x;
    if(balance_peek(s)!='!'){
        x = balance_pop(s);
        string_formation(s);
        final_string += x;
    }
}
int main(){
    struct balance_stack s;
    s.top = -1;
    s.size = 20;
    char x[] = "{{{}}}";
    int count = sizeof(x) / sizeof(x[0]);
    balance_push(s, x[0]);
    for (int i = 1; i < count; i++)
    {
        char incoming_character = x[i];
        char existing_character = balance_peek(s);
        if(incoming_character=='}'){
            if(existing_character=='{'){
                balance_push(s, incoming_character);
            }
            else{
                char popoff = balance_pop(s);
                balance_push(s, incoming_character);
                balance_push(s, popoff);
            }
        }
        else{
            balance_push(s, incoming_character);
        }
    }
    string_formation(s);
    final_string = final_string.substr(0, final_string.length() - 1);
    if(final_string.compare(x)==0){
        cout << "T";
    }
    else
    {
        cout << "F";
    }

}