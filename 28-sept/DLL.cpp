#include <iostream>
using namespace std;
typedef struct dlnode
{
    struct dlnode *left;
    int data;
    struct dlnode *right;
} dlink;

void append(dlink *&D, int x)
{
    dlink *d = D, *temp = new dlink;
    if (d)
    {
        while (d->right)
        {
            d = d->right;
        }
        d->right = temp;
        temp->data = x;
        temp->right = nullptr;
        temp->left = d;
    }
    else
    {
        D = new (dlink);
        d = D;
        d->left = nullptr;
        d->data = x;
        d->right = nullptr;
    }
}
void prepend(dlink *&D, int x)
{
    if (D)
    {
        dlink *temp = new (dlink);
        D->left = temp;
        temp->left = nullptr;
        temp->data = x;
        temp->right = D;
        D = temp;
    }
    else
        cout << "underflow";
}
int pop_back(dlink *&D)
{
    dlink *d = D;
    if (d)
    {
        while (d->right)
        {
            d = d->right;
        }
        if (d->left)
        {
            d->left->right = nullptr;
            d->left = nullptr;
        }
        else
        {
            D = nullptr;
        }
        return (d->data);
    }
    return -1;
}
int pop_front(dlink *&d)
{
    int t = -1;
    if (d)
    {
        t = d->data;
        d = d->right;
    }
    return t;
}
void print(dlink *d)
{
    while (d->right)
    {
        cout << d->data << " ";
        d = d->right;
    }
    cout << d->data << " ";
}
dlink *find_k(dlink *d, int k)
{
    while (d)
    {
        if (k == d->data)
            return d;
        d = d->right;
    }
    return nullptr;
}
void insert_after(int x, int y, dlink *d)
{
    dlink *req = find_k(d, x), *temp = new (dlink);

    temp->data = y;
    temp->right = req->right;
    req->right->left = temp;
    temp->left = req;
    req->right = temp;
}
void insert_before(int x, int y, dlink *d)
{
    dlink *req = find_k(d, x), *temp = new (dlink);

    req->left->right = temp;
    req->left = temp;
    temp->data = y;
    temp->right = req;
}
void delete_k(dlink *d, int k)
{
    dlink *temp = new dlink, *req = find_k(d, k);
    req->left->right = req->right;
    req->right->left = req->left;
}
void swap_data(int a, int b, dlink *d)
{
    dlink *d1 = find_k(d, a);
    dlink *d2 = find_k(d, b);
    d1->data = b;
    d2->data = a;
}
void swap_pointers(dlink *a, dlink *b)
{
    int x = a->data;
    int y = b->data;
    a->data = y;
    b->data = x;
}
bool exit_partition(dlink *lptr, dlink *hptr)
{
    if (!hptr)
        return true;
    //exit condition : find_k(lptr,hptr.data) == nullptr  i.e you cant find the data value of hptr value in lptr
    return (!find_k(lptr, hptr->data)) ? true : false;
}
dlink *partition(dlink *lptr, dlink *hptr)
{
    dlink *pivot = lptr, *d = lptr;
    while (!exit_partition(lptr, hptr) && d)
    {
        if (pivot->data < lptr->data)
        {
            lptr = lptr->right;
        }
        else
        {
            swap_pointers(lptr, d);
        }
        d = d->right;
    }
    swap_pointers(pivot, lptr);
    return lptr;
}
void quick_sort(dlink *lptr, dlink *hptr)
{
    dlink *pivot = partition(lptr, hptr);

    if (!exit_partition(lptr, pivot->left))
        quick_sort(lptr, pivot->left);
    if (!exit_partition(pivot->right, hptr))
        quick_sort(pivot->right, hptr);
}
int get_length(dlink *d)
{
    int i = 0;
    while (d)
    {
        d = d->right;
        i++;
    }
    return i;
}
int main()
{
    dlink *d = new (dlink);
    int data;

    // cin >> data;
    // d->data = data;
    // d->left = nullptr;
    // d->right = nullptr;
    d = nullptr;

    while (true)
    {
        cin >> data;
        if (data == -1)
            break;
        append(d, data);
    }
    cout << get_length(d);
    // print(d); //1
    // int k;
    // cin >> k;
    // prepend(d, k);
    // print(d);//2
    // cin >> k;
    // append(d, k);
    // print(d); //3
    // int x, y;
    // cin >> x >> y;
    // insert_before(y,x, d);
    // print(d);//4
    // cin >> x >> y;
    // insert_after(y, x,d);
    // print(d);//5
    // pop_front(d);
    // print(d);//6
    // pop_back(d);
    // print(d);//7
    // cin >> k;
    // delete_k(d, k);//8
    // print(d);

    // dlink *lptr = d, *hptr;
    // while (d->right)
    // {
    //     d = d->right;
    // }
    // hptr = d;
    // d = lptr;
    // quick_sort(lptr, hptr);
    // print(d);
}