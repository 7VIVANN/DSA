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

void find_k(link *l, int k, link *l2)
{
    while (l->next)
    {
        if (k == l->data)
        {
            while (l2->next)
            {
                l2 = l2->next;
            }
            l2->next = l;
            return;
        }
        l = l->next;
    }
    if (l->data == k)
    {
        while (l2->next)
        {
            l2 = l2->next;
        }
        l2->next = l;
    }
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
int delete_end(link *&L) //pop
{
    link *l;
    l = L;
    int t = -1;
    if (l->next)
    {
        while (l->next)
        {
            if (!l->next->next)
            {
                t = l->next->data;
                l->next = nullptr;
                return t;
            }
            l = l->next;
        }
    }
    return t;
}
int peek(link *&L) //pop
{
    link *l;
    l = L;
    int t = -1;
    if (l->next)
    {
        while (l->next)
        {
            if (!l->next->next)
            {
                t = l->next->data;
                return t;
            }
            l = l->next;
        }
    }
    return t;
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

    find_k(L,6,L2);


    //start checking fropm back of both lists if differnt print element
    int temp = -1;
    while (true)
    {
        int d1 = peek(L);
        int d2 = peek(L2);

        if(d1!=d2)
            {
                
                cout << temp;
                break;
            }
        else
        {
            temp = d1;
            delete (L);
        }
        
    }
    
}
