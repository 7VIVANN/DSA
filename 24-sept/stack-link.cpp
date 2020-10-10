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
void add_end(link *&L, int x) //enque or push
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
int delete_front(link *&L) //deque
{
    int t = -1;
    if (L->next)
    {
        t = L->data;
        L = L->next;
    }
    return t;
}
int delete_end(link *&L)  //pop
{
    link *l;
    l = L;
    int t = -1;
    if(l->next){
        while (l->next)
        {
            if (l->next)
            {
                if (!l->next->next)
                {
                    t = l->next->data;
                    l->next = nullptr;
                    return t;
                }
                else
                {
                    t = l->data;
                    l->data = -1;
                    return t;
                }
                
                
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

    //STACK FUNCTIONS
    //input
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        add_end(L, x); //push
    }
    //pop all elements
    while (peek(L)!=-1) //peek
    {
        cout << delete_end(L)<<" "; //pop
    }
    cout << endl;

    //QUEUE FUNCTIONS
    //input
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        add_end(L, x); //enque
    }

    while (true) 
    {
        int t = delete_front(L); //deque
        if(t==-1)
            break;
        cout << t << " ";
    }
    cout << endl;
}
