#include <iostream>
#include <string>
using namespace std;
struct two_stack_stack
{
    int size;
    int top; //DIAGRAM
};

void two_stack_push(struct two_stack_stack &s, int x)
{
    s.size++;
    if (s.top == s.size - 1)
        cout << "two_stack_stack overflow";
    else
        ++s.top;
}
int two_stack_pop(struct two_stack_stack &s)
{
    s.size--;
    if (s.top ==-1)
        return -1;
    else
        return s.top--;
}
int two_stack_peek(struct two_stack_stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.top;
}
int main(){
    int n=5;
    int ar[] = {0, 0, 0, 0, 0};
    struct two_stack_stack s[2];
    s[0].top = -1;
    s[1].top = -1;
    s[0].size = 0;
    s[1].size = 0;
    cout << "(1 s1 or 2 s2) (value) (1 two_stack_push -1 two_stack_pop 0 two_stack_peek) ( value 0 incase of two_stack_peek and two_stack_pop )"<<endl;    
    while(s[0].size+s[1].size<n){
        int a, b, c;
        cin >> a >> b >> c;
        switch (c)
        {
        case 1:
            two_stack_push(s[a - 1], b);
            ar[a == 1 ? s[0].size :n - s[1].size] = b;
            break;
        case -1:
            cout<<ar[a == 1 ? two_stack_peek(s[a - 1])+1 : n - two_stack_peek(s[a - 1])-1]<<endl;
            ar[a == 1 ? two_stack_pop(s[a - 1])+1 : n -1- two_stack_pop(s[a - 1])] = 0;
            break;
        case 0:
            cout << ar[a == 1 ? two_stack_peek(s[a - 1])+1 : n - two_stack_peek(s[a - 1])-1]<<endl;
            break;
        }
    }
    cout << "no more can be entered ";
}