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
        cout << l->data <<" " ;
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
    cout << x <<" " ;
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
int get_i(int n,link *l){
    int i = 1;
    while (l->next)
    {
        if(i==n){
            return l->data;
        }
        i++;
        l = l->next;
    }
    return l->data;
}
void put_i(int n,int k, link *&l)
{
    int i = 1;
    while (l->next)
    {
        if (i == n)
        {
            l->data = k;
            return;
        }
        i++;
        l = l->next;
    }
}
int partition(link *ar, int low, int high)
{
    int pi = low;
    if (low < high)
    {
        for (int i = low + 1; i < high; i++)
        {
            if (get_i(pi,ar) > get_i(i,ar))
            {
                low++;
                // swap(ar[i], ar[low]);
                int t = get_i(pi, ar);
                int b = get_i(i,ar);
                put_i(pi, b,ar);
                put_i(i, t, ar);

            }
        }
        // swap(ar[pi], ar[low]);
        int t = get_i(pi, ar);
        int b = get_i(low,ar);
        put_i(pi, b, ar);
        put_i(low, t, ar);

        pi = low;
    }
    return pi;
}
void quicksort(link *ar, int low, int high)
{
    int pi = partition(ar, low, high);

    if (low < pi - 1)
        quicksort(ar, low, pi - 1);
    if (pi + 1 < high)
        quicksort(ar, pi + 1, high);
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
    quicksort(L, 1, get_length(L)-1);
    print(L);
}
