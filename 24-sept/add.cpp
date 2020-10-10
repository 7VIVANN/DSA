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
        cout << l->data <<" ";
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
    if (x != 0)
        cout << x << " ";
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
        cout <<"error" ;
    }
}
void delete_front(link *&L)
{
    if (L->next)
        L = L->next;
    else
        cout << "underflow";
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


void add(link *l1, link *l2, link *&result)
{
    int sum = 0, carry = 0;
    int d1, d2;
    while (true)
    {
        d1 = delete_end(l1);
        d2 = delete_end(l2);
        if (d1 == -1)
            break;
        cout << d1 << d2 << " ";
        sum = (d1 + d2 + carry) % 10;
        carry = (d1 + d2 + carry) / 10;

        add_end(result, sum);

        
    }
    add_end(result, carry); 
}
void adjust(link *&l,int n){
    int i = 0;
    while(i<n){
        add_front(l, 0);
        i++;
    }
}
int main()
{
    int n;

    link *l1;
    l1 = new (link);

    int x;
    cin >> x;
    l1->data = x;
    l1->next = nullptr;

    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        add_end(l1, x);
    }
    
    link *l2;
    l2 = new (link);

    cin >> x;
    l2->data = x;
    l2->next = nullptr;

    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        add_end(l2, x);
    }
   
    int len1 = get_length(l1);
    int len2 = get_length(l2);

    if (len1<len2)
    {
        adjust(l1, len2 - len1);
        
        }
    else if(len1 > len2 )
    {
        adjust(l2, len1 - len2);
       
    }
    
    
    link *result;
    result = new (link);

    result->data = 0;
    result->next = nullptr;

    add(l1, l2, result);

    print_rev(result);
}
