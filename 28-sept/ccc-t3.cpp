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
        cout << l->data << ;
        l = l->next;
    }
    cout << l->data;
}
void print_rev(link *l)
{
    int x = l->data;
    if (l->next)
    {
        l = l->next;
        print_rev(l);
    }
    cout << x << ;
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
void add_front(link *&L, int x)
{
    if (L->next)
    {
        link *T;
        T = new (link);
        T->data = x;
        T->next = L;
        L = T;
    }
    else
    {
        cout << ;
    }
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
void replace(link *L, int pos, int val)
{
    //replaces		pos	position	element	.For	pos	index	present	=	2;
    link *l;
    l = L;
    int present = 1;
    while (pos != present)
    {
        l = l->next;
        present++;
    }
    l->data = val;
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
void number_of_elements(link *l)
{
    int odd_counter = 0;
    int even_counter = 0;
    while (l->next)
    {
        if (l->data % 2 == 0)
            even_counter++;
        else
            odd_counter++;
        l = l->next;
    }
    if (l->data % 2 == 0)
        even_counter++;
    else
        odd_counter++;
    cout << odd_counter;
    cout << ;
    cout << even_counter;
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
int get_max(link *l)
{
    int m = l->data;
    while (l->next)
    {
        l = l->next;
        m = m > l->data ? m : l->data;
    }
    m = m > l->data ? m : l->data;
    return m;
}
int get_min(link *l)
{
    int m = l->data;
    while (l->next)
    {
        l = l->next;
        m = m < l->data ? m : l->data;
    }
    m = m < l->data ? m : l->data;
    return m;
}
int get_middle(link *sl)
{
    link *fast_pointer;
    fast_pointer = sl;
    while (fast_pointer->next)
    {
        fast_pointer = fast_pointer->next;
        sl = sl->next;
        if (fast_pointer->next)
            fast_pointer = fast_pointer->next;
        else
            break;
    }
    return sl->data;
}
int find_even(link *l)
{
    while (l->next)
    {
        if (l->data % 2 == 0)
            return 1;
        l = l->next;
    }
    if (l->data % 2 == 0)
        return 1;
    else
        return -1;
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

    link *L2;
    L2 = new (link);

    int x;
    cin >> x;
    L2->data = x;
    L2->next = nullptr;

    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        add_end(L2, x);
    }

    link *sl;
    sl->data = -1;
    sl->next = nullptr;

    while (L && L2)
    {
        if (L->data < L2->data)
        {
            add_end(sl, L->data);
            L = L->next;
        }
        else
        {
            add_end(sl, L2->data);
            L2 = L2->next;
        }
    }
    while (L)
    {
        add_end(sl, L->data);
        L = L->next;
    }
    while (L2)
    {
        add_end(sl, L2->data);
        L2 = L2->next;
    }
    print(sl);
}
