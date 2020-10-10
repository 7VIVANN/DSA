#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} link;
void print(link *l){
    link *head = l;
    while (true)
    {
        cout << char(l->data+65);
        l = l->next;
        if(l==head)
            break;
    }
    
}
void append(link *l, int x)
{
    while (l->next)
        l = l->next;
    link *temp = new link;
    temp->data = x;
    temp->next = nullptr;
    l->next = temp;
}
void init(link *l, int n)
{
    int x=0, i = 0;
    l->data = x;
    l->next = nullptr;
    i++;
    while (i < n)
    {
        append(l, x);
        i++;
    }
    link *temp = l;
    while (temp->next)
        temp = temp->next;
    temp->next = l;
}
void execute(link *l, int m)
{
    int i = 1;
    int number = 0;
    while (number<15)
    {
        if (i == m - 1 && l->next->data==0)
        {
            l->next->data=1;
            i = 0;
            number++;
        }
        else
        {
            l = l->next;
            if(l->data==0)
            i++;
        }
    }
}
int main()
{
    link *l = new link;

    int n; //number of people
    n = 30;
    init(l, n);
    int m;
    m = 9; //index to be executed
    execute(l, m);
    print(l);
}