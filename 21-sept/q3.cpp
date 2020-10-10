#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} link;
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
int pop_front(link *&L)
{
    if (L->next)
    {
        int val = L->data;
        L = L->next;
        return val;
    }

    else
        return -1;
}
void print(link *l)
{
    while (l->next)
    {
        cout << l->data << " ";
        l = l->next;
    }
    cout << l->data;
}
void rev(link *&l)
{
    int x = l->data;
    if (l->next)
    {
        l = l->next;
        rev(l);
    }
    add_end(l, x);
}
link *reverse_link(link *&l)
{
    rev(l);
    int fisj = pop_front(l);
    return l;
}
link* extract(link* l,int x ,int i){
    while (l->next)
    {
        if(x==i)
        {
            link *temp = l;
            return temp;
        }
        x++;
        if(l->next)
        l = l->next;
    }

    return l;
}
link* get(link *l1,int x,int i){
    link *l2;
    l2 = new (link);
    l2->data = l1->data;
    l2->next = nullptr;
    l1 = l1->next;
    while (x<i)
    {
        add_end(l2, l1->data);
        l1 = l1->next;
        x++;
    }
    add_end(l2, l1->data);
    return l2;
}
int main(){
    int n;

    link *l1,*l2,*l3;
    l1 = new (link);
    l2 = new (link);

    cin >> n;
    l1->data = n;
    l1->next = nullptr;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        add_end(l1, n);
    }
    
    l3 = extract(l1, 0, 2);
    l1->next=l3;
    l2 = get(l1, 1, 5);
    l1->next = rev(l2);
    print(l1);
}

