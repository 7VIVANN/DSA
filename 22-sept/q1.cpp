#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} link;

void print(link *l)
{
    while (l->next)
    {
        cout << l->data<<" " ;
        l = l->next;
    }
    cout << l->data;
}
void add_end(link *&L, int x)
{
    link *l;
    l = L;
    while (l->next)
    {
        l = l->next;
    }
    link *t;
    t = new (link);
    t->data = x;
    t->next = nullptr;
    l->next = t;
}

int get_length(link *l)
{
    int len = 0;
    while (l->next)
    {
        len++;
        l = l->next;
    }
    return len + 1; //pre	for	first	element	post	for	last	element
}

int is_loop(link *l){
    link *fast_pointer, *slow_pointer;
    slow_pointer = l;
    fast_pointer = l;
    do
    {
        if(fast_pointer->next==nullptr || slow_pointer->next==nullptr)
        {
            return -1;
        }
        slow_pointer = slow_pointer->next;
        if (fast_pointer->next)
        {
            fast_pointer = fast_pointer->next;
            if (fast_pointer->next)
            {
                fast_pointer = fast_pointer->next;
            }
        }
    }
    while (fast_pointer != slow_pointer);

    return slow_pointer->data;
}
link* get_5(link* l){
    int i = 1;
    while (l->next)
    {
        if(i==5)
            return l;
        l = l->next;
        i++;
    }
    
}
int main()
{
    int n;

    link *L,*l;
    L = new (link);

    int x;
    cin >> x;
    L->data = x;
    L->next = nullptr;

    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        add_end(L, x);
    }
    l = L;
    while (l->next)
    {
        l = l->next;
    }
    l->next = get_5(L);
    if(is_loop(L)<0)
        cout << 0;
    else
    {
        cout << 1 << "\n" << get_5(L)->data;
    }
    
}
