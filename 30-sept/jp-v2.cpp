#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} link;
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
    int x, i = 1;
    l->data = i++;
    l->next = nullptr;
    while (i <= n)
    {
        append(l, i++);
    }
    link *temp = l;
    while (temp->next)
        temp = temp->next;
    temp->next = l;
}
void execute(link *l, int m)
{
    int i = 1;
    while (l->next != l)
    {
        if (i == m - 1)
        {
            // cout << l->next->data << " ";
            l->next = l->next->next;
            i = 0;
        }
        else if (i == m - 2)
        {
            // cout << l->next->data << " ";
            l->next = l->next->next;
            i++;
        }
        else
        {
            l = l->next;
            i++;
        }
    }
}
int main()
{
    link *l = new link;

    int n; //number of people
    cin >> n;
    init(l, n);

    int m;
    m = 3; //index to be executed
    execute(l, m);

    cout << l->next->data << " ";
}