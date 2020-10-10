#include <iostream>
#include <string>
using namespace std;
union u
{
    int i;
    char c;
    float f;
    bool b;
};
struct generic_stack
{
    int size;
    int top; //DIAGRAM
    union u elements[10];
    int tag[10];
};

void generic_push (struct generic_stack &s, union u &x, int t)
{
    if (s.top == s.size - 1)
        cerr << "generic_stack overflow ";
    else
    {
        switch (t)
        {
        case 0:
            s.elements[++s.top].i = x.i;
            s.tag[s.top] = t;
            break;
        case 1:
            s.elements[++s.top].c = x.c;
            s.tag[s.top] = t;
            break;
        case 2:
            s.elements[++s.top].f = x.f;
            s.tag[s.top] = t;
            break;
        case 3:
            s.elements[++s.top].b = x.b;
            s.tag[s.top] = t;
            break;
        default:
            break;
        }
    }
}
union u generic_pop(struct generic_stack &s)
{
    if (s.top == -1)
        cerr << "generic_stack empty ";
    else
    {
        return s.elements[s.top--];
    }
}
union u generic_peek(struct generic_stack &s)
{
    if (s.top == -1)
        cerr << "generic_stack empty ";
    else
    {
        return s.elements[s.top];
    }
}
int main()
{
    struct generic_stack s1;
    s1.top = -1;
    s1.size = 20;
    s1.elements[0].i = 1;
    s1.elements[1].b = true;
    s1.elements[2].f = 1.0;
    s1.elements[3].c = 'd';
    s1.elements[4].i = 1;
    s1.elements[5].b = true;
    s1.elements[6].f = 1.0;
    s1.elements[7].c = 'd';
    s1.top = 7;
    int tag[8] = {0, 3, 2, 1, 0,3,2,1};
    for (int i = 0; i < 10; i++)
    {
        generic_push (s1, s1.elements[i], tag[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        union u element = generic_peek(s1);
        switch (s1.tag[i])
        {
        case 0:
           cout<<element.i;
            break;
        case 1:
           cout<<element.c;
            break;
        case 2:
           cout<<element.f;
            break;
        case 3:
           cout<<element.b;
            break;;
        default:
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        union u element = generic_pop(s1);
        switch (s1.tag[i])
        {
        case 0:
            cout << element.i;
            break;
        case 1:
            cout << element.c;
            break;
        case 2:
            cout << element.f;
            break;
        case 3:
            cout << element.b;
            break;
        default:
            break;
        }
    }
}
