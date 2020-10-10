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
void print(dlink *d)
{
    while (d->right)
    {
        cout << d->data << " ";
        d = d->right;
    }
    cout << d->data << " ";
}

int get_length(dlink *d){
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
    char x;

    dlink *d1 = new (dlink);
    int data;
    d1 = nullptr;

    while (true)
    {
        cin >> x;
        if(x=='#')
            break;
        data = (int)x - 48;
        append(d1, data);
    }

    dlink *d2 = new dlink;
    d2 = nullptr;
    while (true)
    {
        cin >> x;
        if (x == '#')
            break;
        data = (int)x - 48;
        append(d2, data);
    }

    int l1 = get_length(d1);
    int l2 = get_length(d2);

    dlink *d3 = new dlink;
    d3 = nullptr;
    append(d3, 0);

    if(l2>l1){
        for (int i = 0; i < l2-l1; i++)
        {
            prepend(d2, 0);
        }
        int sum = 0, carry = 0;
        for (int i = 0; i < l2; i++)
        {
            int a = pop_back(d1);
            int b = pop_back(d2);
             sum = (a + b+carry) % 10;
             carry = (a + b+carry)/ 10;
            prepend(d3, sum);
        }
        prepend(d3, carry);
    }
    else
    {
        for (int i = 0; i < l1 - l2; i++)
        {
            prepend(d1, 0);
        }
        int sum = 0, carry = 0;
        for (int i = 0; i < l1; i++)
        {
            int a = pop_back(d1);
            int b = pop_back(d2);
            sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            prepend(d3, sum);
        }
        prepend(d3, carry);
    }
    pop_back(d3);
    int k=pop_front(d3);
    while(k==0){
        k = pop_front(d3);
    }
    prepend(d3, k);
    print(d3);
}