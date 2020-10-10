#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void print(struct node *l)
{
    while (l->next)
    {
        cout << l->data << " ";
        l = l->next;
    }
    cout << l->data;
}
void print_rev(struct node *l)
{
    int x = l->data;
    if (l->next)
    {
        l = l->next;
        print_rev(l);
    }
    if(x!=0)
    cout << x << " ";
}
void add_end(struct node *&L, int x)
{
    struct node *l;
    l = L;
    while (l->next)
    {
        l = l->next;
    }
    struct node *t;
    t = new (struct node);
    t->data = x;
    t->next = nullptr;
    l->next = t;
}
void add_front(struct node *&L, int x)
{
    if (L->next)
    {
        struct node *T;
        T = new (struct node);
        T->data = x;
        T->next = L;
        L = T;
    }
    else
    {
        cout << "underflow";
    }
}
void delete_front(struct node *&L)
{
    if (L->next)
        L = L->next;
    else
        cout << "underflow";
}
void delete_end(struct node *&L)
{
    struct node *l;
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
void insert(struct node *&L, int pos, int val,int present)
{
    //inserts AT pos index with present = 1 ie insert before 
    //insrets AT pos+1 index with present = 0 ie insert after
    struct node *l;
    l = L;
    while (pos != present)
    {
        l = l->next;
        present++;
    }
    struct node *T;
    T = new (struct node);
    T->data = val;
    T->next = l->next;
    l->next = T;
}
void find_and_insert(struct node* &L,int required,int val,int present){
    struct node *l;
    l = L;
    if(present == 0){
        if(l->data == required){
            add_front(L, val);
            return;
        }
        while (l->next)
        {
            if(l->next->data == required){
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
    if (present == 1)
    {
        while (l->next)
        {
            if (l->data == required)
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
        if(l->data==required){
            add_end(L, val);
        }
    }
}
void find_and_remove(struct node* &L,int val){
    struct node *l;
    l = L;
    if(l->data==val){
        L = l->next;
    }
    while(l->next){
        if(l->next->data==val){
            if(l->next->next){
                l->next = l->next->next;
            }
            else
            {
                l->next = nullptr;
            }
            break;
        }
        l = l->next;
    }
}
void replace(struct node *L, int pos, int val)
{
    //to replaces element WITH position p present = 1
    //to replace element WITH index p present = 0
    struct node *l;
    l = L;
    int present = 0;
    while (pos != present)
    {
        l = l->next;
        present++;
    }
    l->data = val;
}
int find(struct node *l, int k)
{
    int i = 0;
    while (l->next)
    {
        if (k == l->data)
        {
            return i;
        }
        l = l->next;
        i++;
    }
    if (l->data == k)
        return i;
    else
        return -1;
}
int get_length(struct node *l)
{
    int len = 0;
    while (l->next)
    {
        len++;
        l = l->next;
    }
    return len + 1; //pre for first element post for last element
}
int get_max(struct node *l)
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
int get_min(struct node *l)
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

int main()
{
    int n;
    int k, x, y;
    struct node *L;
    L = new (struct node);

    int temp;
    cin >> temp;
    L->data = temp;
    L->next = nullptr;

    while (true)
    {
        cin >> temp;
        if (temp == -1)
            break;
        add_end(L, temp);
    }

    print(L);
    cout << "\n";

    cin >> k;
    add_front(L,k);

    print(L);
    cout << "\n";

    cin >> x >> y;
    find_and_insert(L, x, y, 0);

    print(L);
    cout << "\n";

    cin >> x >> y;
    find_and_insert(L, x, y, 1);

    print(L);
    cout << "\n";

    cin >> k;
    find_and_remove(L, k);

    print(L);
    cout << "\n";

    find_and_remove(L, get_min(L));

    print(L);
    cout << "\n";

    find_and_remove(L, get_max(L));

    print(L);

}