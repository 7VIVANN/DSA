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
int get_length(link *l)
{
    int len = 0;
    while (l->next)
    {
        len++;
        l = l->next;
    }
    return len + 1; //pre for first element post for last element
}
int find(struct node *l, int k)
{
    while (l->next)
    {
        if (k == l->data)
        {
            return k;
        }
        l = l->next;
    }
    if (l->data == k)
        return k;
    else
        return -1;
}

link *union_link(link *l1, link *l2)
{
    link *l3;
    l3 = new (link);

    if(l2->data>l1->data){
        l3->data = l1->data;
        l1 = l1->next;
    }
    else
    {
        l3->data = l2->data;
        l2 = l2->next;
    }
    l3->next = nullptr;

    while (l1->next && l2->next)
    {
        if (l1->data > l2->data)
        {
            if (find(l3, l2->data) < 0)
                add_end(l3, l2->data);
            l2 = l2->next;
        }
        else
        {
            if (find(l3, l1->data) < 0)
                add_end(l3, l1->data);
            l1 = l1->next;
        }
    }
    
    while (l1->next)
    {
        if (find(l3, l1->data) < 0)
            add_end(l3, l1->data);
        l1 = l1->next;
    }
    if (find(l3, l1->data) < 0)
        add_end(l3, l1->data);

    while (l2->next)
    {
        if (find(l3, l2->data) < 0)
            add_end(l3, l2->data);
        l2 = l2->next;
    }
    if (find(l3, l2->data) < 0)
        add_end(l3, l2->data);

    return l3;
}
link *intersection_link(link *l1, link *l2)
{
    link *l3;
    l3 = new (link);

    l3->data = -1; // arbitrary initialiser
    l3->next = nullptr;

    while (l1->next)
    {
        if (find(l2, l1->data) > 0)
        {
            add_end(l3, l1->data);
        }
        l1 = l1->next;
    }
    if (find(l2, l1->data) > 0)
    {
        add_end(l3, l1->data);
    }

    return l3;
}
link *diff_link(link *l1, link *l2)
{
    link *l3;
    l3 = new (link);

    l3->data = -1; // arbitrary initialiser
    l3->next = nullptr;

    while (l1->next)
    {
        if (find(l2, l1->data) < 0)
        {
            add_end(l3, l1->data);
        }
        l1 = l1->next;
    }
    if (find(l2, l1->data) < 0)
    {
        add_end(l3, l1->data);
    }

    return l3;
}

link *unsorted_union_link(link *l1, link *l2)
{
    link *l3;
    l3 = new (link);

    l3->data = l1->data;
    l3->next = nullptr;

    l1 = l1->next;
    while (l1->next)
    {
        add_end(l3, l1->data);
        l1 = l1->next;
    }
    add_end(l3, l1->data);

    while (l2->next)
    {
        if(find(l3,l2->data)<0)
            add_end(l3, l2->data);
        l2 = l2->next;
    }
    if (find(l3, l2->data) < 0)
        add_end(l3, l2->data);

    return l3;
}

int main()
{
    int n;

    link *l1, *l2;
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

    cin >> n;
    l2->data = n;
    l2->next = nullptr;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        add_end(l2, n);
    }

    link *l3;
    l3 = union_link(l1, l2);
    print(l3);
    cout << endl;

    l3 = intersection_link(l1, l2);
    if(l3->next)
        l3 = l3->next;
    print(l3);
    cout << endl;

    l3 = diff_link(l1, l2);
    if (l3->next)
        l3 = l3->next;
    print(l3);
    cout << endl;

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

    cin >> n;
    l2->data = n;
    l2->next = nullptr;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        add_end(l2, n);
    }

    l3 = unsorted_union_link(l1, l2);
    print(l3);
    cout << endl;

    l3 = intersection_link(l1, l2);
    if (l3->next)
        l3 = l3->next;
    print(l3);
    cout << endl;

    l3 = diff_link(l1, l2);
    if (l3->next)
        l3 = l3->next;
    print(l3);
    cout << endl;
}