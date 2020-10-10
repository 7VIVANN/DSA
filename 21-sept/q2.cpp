#include <iostream>
using namespace std;
union u
{
    char b;
    int a;
};
typedef struct node
{
    union u data;
    int tag;
    struct node *next;
} link;
void add_end(link *&L, union u x, int tag)
{
    link *l;
    l = L;
    while (l->next)
    {
        l = l->next;
    }
    link *t;
    t = new (link);
    switch (tag)
    {
    case 1:
        t->data.a = x.a;
        t->tag = tag;
        break;
    case 0:
        t->data.b = x.b;
        t->tag = tag;
        break;

    default:
        break;
    }
    t->next = nullptr;
    l->next = t;
}
void add_front(link *&L, union u x, int tag)
{
    // if (L->next)
    // {
        link *T;
        T = new (link);
        switch (tag)
        {
        case 1:
            T->data.a = x.a;
            T->tag = tag;
            break;
        case 0:
            T->data.b = x.b;
            T->tag = tag;
            break;

        default:
            break;
        }
        T->next = L;
        L = T;
    // }
    // else
    // {
    //     cout << "underflow";
    // }
}
int main()
{
    link *l;
    l = new (link);

    int tag;
    union u x;

    cin >> tag;
    switch (tag)
    {
    case 0:
        cin >> x.a;
        break;
    case 1:
        cin >> x.b;
        break;

    default:
        break;
    }

    l->data = x;
    l->next = nullptr;

    bool condition = true;
    while (condition)
    {
        cin >> tag;
        switch (tag)
        {
        case 0:
            cin >> x.a;
            add_front(l, x, tag);
            break;
        case 1:
            cin >> x.b;
            if (x.b == '#')
            {
                condition = false;
                continue;
            }
            add_end(l, x, tag);
            break;
        default:
            break;
        }
    }
}