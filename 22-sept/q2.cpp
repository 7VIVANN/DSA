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
        cout << l->data << " ";
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

void delete_front(link *&L)
{
    if (L->next)
        L = L->next;
    else
        cout << "underflow";
}
void delete_end(link *&L)
{
    link *l;
    l = L;
    while (l->next)
    {
        if (!l->next->next)
        {
            l->next = nullptr;
            break;
        }
        l = l->next;
    }
}
void insert(link *&L, int pos, int val)
{
    //inserts	after	pos+1	index
    link *l;
    l = L;
    int present = 0;
    while (pos != present)
    {
        l = l->next;
        present++;
    }
    link *T;
    T = new (link);
    T->data = val;
    T->next = l->next;
    l->next = T;
}

void find(link *l, int k)
{
    while (l->next)
    {
        if (k == l->data)
        {
            cout << 1;
            return;
        }
        l = l->next;
    }
    if (l->data == k)
        cout << 1;
    else
        cout << 0;
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
link *get_n(int n, link *l)
{
    int i = 1;
    while (l->next)
    {
        if (i == n)
            return l;
        l = l->next;
        i++;
    }
    if (i == n)
        return l;
    return nullptr;
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
    link *l;
    link *t;
    l = L;
    while (l->next)
    {
        int val = l->data;
        val = val < 0 ? -val : val;
        t = get_n(val, L);
        if (t && t->data>0)
            t->data = -t->data;
        l = l->next;
    }

    int val = l->data;
    val = val < 0 ? -val : val;
    t = get_n(val, L);
    if (t && t->data>0)
        t->data = -t->data;

    l = L;
    while (l->next)
    {
        if(l->data>0)
            cout << l->data << " ";
        l = l->next;
    }
    if (l->data > 0)
        cout << l->data << " ";
}
