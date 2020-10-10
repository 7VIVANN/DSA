#include <iostream>
#include <string>
using namespace std;
struct bubble_stack
{
    int size;
    int top; //DIAGRAM
    int elements[20];
};

void bubble_push(struct bubble_stack &s, int x)
{
    if (s.top == s.size - 1)
        cerr << "bubble_stack overflow ";
    else
        s.elements[++s.top] = x;
}
int bubble_pop(struct bubble_stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top--];
}
int bubble_peek(struct bubble_stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top];
}
int main(){
    int n=6;
    int ar[] = {3, 2, 4, 1, 5, 6};
    int m;
    struct bubble_stack small;
    struct bubble_stack  big;
    small.top= -1;
    small.size = 2*n;
    big.top = -1;
    big.size = 2*n;

    m = ar[0];
    for (int i = 1; i < n; i++)
    {
        bubble_push(small,m > ar[i] ? ar[i] : m);
        m = m > ar[i] ? m : ar[i];
    }
    while(bubble_peek(small)!=-1){
        int o = bubble_pop(small);
        bubble_push(big, m > o ? m : o);
        m = m < o ? m : o;
    }
    bubble_push(big, m);
    while(bubble_peek(big)!=-1){
        cout << bubble_pop(big);
    }
}