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
int main()
{
    int n;
cin >> n;

    link *l[n];
    for (int i = 0; i < n; i++)
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
        l[i] = L;
    }
    
    link *ar[10];
    for (int i = 0; i < 10; i++)
    {
        ar[i]->data = -1;
        ar[i]->next = nullptr;
    }
    
    for (int i = 0; i < n; i++)
    {
        link *L;
        L = l[i];

        while (L)
        {
            x = L->data;
            add_end(l[x % 10], x);
            L = L->next;  
        }
    }

    for (int i = 0; i < 10; i++)
    {
        ar[i] = ar[i]->next;
    }

    int a = get_length(l[0]), b = get_length(l[0]), c = get_length(l[0]);

    for (int i = 0; i < 10; i++)
    {
        if (get_length(l[i])>c)
        {
            if (get_length(l[i]) > b)
            {
                if (get_length(l[i]) > a)
                {
                }
                else
                {
                    /* code */
                }
                
            }
            else
            {
                /* code */
            }
            

        }
        
    }
    
}


