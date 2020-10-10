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
void print(link *l)
{
    while (l->next)
    {
        cout << l->data << " ";
        l = l->next;
    }
    cout << l->data;
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
int rearrange(int to_be_copied, link *temp)
{
    int hold = -1;
    if (temp->next)
    {
        hold = temp->data;
        temp->data = to_be_copied;
        temp = temp->next;
        return rearrange(hold, temp);
        ;
    }
    else
    {
        hold = temp->data;
        temp->data = to_be_copied;
        return hold;
    }
}
void reorder_insert(link *l){
    int i = 1;
    int length = get_length(l);
    l = l->next;
    while (i<length-1)
    {
        int copy = rearrange(l->data,l);
        l->data = copy;
        l = l->next;
        if(l->next){
            l = l->next;
        }
        i += 2;
    }
}

int main()
{
    int n;

    link *L;
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
    link *t;
    t = L;
    reorder_insert(t);
    print(L);
}
