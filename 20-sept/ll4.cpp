#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} link;

void print(struct node *l)
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
int pop_end(link *&L)
{
    link *l;
    l = L;
    while (l->next)
    {
        if (!l->next->next)
        {
            int val = l->next->data;
            l->next = nullptr;
            return val;
        }
        l = l->next;
    }
    return l->data;
}
int get_length(link *l)
{
    int len = 0;
    while (l->next)
    {
        len++;
        l = l->next;
    }
    return len + 1;
}
link *copy(link *l)
{
    link *l2;
    l2 = new (link);
    l2->data = l->data;
    l2->next = nullptr;
    l = l->next;

    while (l->next)
    {
        add_end(l2, l->data);
        l = l->next;
    }
    add_end(l2, l->data);

    return l2;
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
        cout << "underflow";
    }
}
//insert before
void find_and_insert(link *&L, int required, int val) 
{
    link *l;
    l = L;
    if (l->data == required)
    {
        add_front(L, val);
        return;
    }
    while (l->next)
    {
        if (l->next->data == required)
        {
            struct node *T;
            T = new (struct node);
            T->data = val;
            T->next = l->next;
            l->next = T;
            return;
        }
        l = l->next;
    }
}
bool is_palindrome(link *l)
{
    link *temp;
    temp = copy(l);
    bool ispal = true;
    while (temp->next)
    {
        if (pop_front(temp) != pop_end(temp))
        {
            ispal = false;
            break;
        }
    }
    return ispal;
}
void delete_duplicate(link *l)
{
    if (l->next)
    {
        if (l->data == l->next->data)
        {
            l->next = l->next->next;
            delete_duplicate(l);
            return;
        }
        l = l->next;
        delete_duplicate(l);
    }
    else
    {
        return;
    }
}
void delete_duplicate_unsorted(link *l)
{
    while (true)
    {

        int val = l->data;
        link *t;
        t = l;
        while (t->next)
        {
            if (val == t->next->data)
            {
                t->next = t->next->next;
                continue;
            }
            t = t->next;
        }
        if (l->next)
            l = l->next;
        else
            break;
    }
}
//sjip 4
void cluster_even(link *l)
{
    while (l->next)
    {
        int a = l->data;
        if (a % 2 != 0)
        {
            link *temp;
            temp = l;
            if (find_even(temp) > 0)
            {
                temp = l->next;
                int b = temp->data;
                temp->data = a;
                while (b % 2 != 0)
                {
                    temp = temp->next;
                    a = b;
                    b = temp->data;
                    temp->data = a;
                }
                l->data = b;
            }
        }
        l = l->next;
    }
}
void insert_sort(link *l)
{
    while (l->next)
    {
        
    }
}
void rev(link* &l){
    int x = l->data;
    if(l->next){
        l = l->next;
        rev(l);
    }
    add_end(l, x);
}
link* reverse_link(link* &l){
    rev(l);
    int fisj = pop_front(l);
    return l;
}
int main()
{
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
    
    print(reverse_link(L));
}
