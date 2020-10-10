#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
    bool is_printed;
} link;
bool is_loop(link *l){
    link *head = l;
    while (l)
    {
        l = l->next;
        if (l->data==head->data && l!=head)
            return true;
        if(l==head)
            break;
    }
    return false;
}

void print_loop(link *l)
{
    link *head = l,*tail=l;
    while (l)
    {
        head = l;
        
        while(is_loop(l) && !l->is_printed){
            l->is_printed = true;
            while (l)
            {
                cout << l->data << " ";
                l = l->next;
                if (l->data == head->data)
                    break;
            }
            cout << head->data << "\n";
            if(l==head)
                break;
        }
        l = head->next;
        while (l->is_printed)
        {
            l = l->next;
            if (l == tail)
                break;
        }
        if (l == tail)
            break;
    }
    
}
void append(link *l, int x)
{
    link *temp = new link; //,*l;
    //l = L;
    while (l->next)
        l = l->next;
    temp->data = x;
    temp->next = nullptr;
    temp->is_printed = false;
    l->next = temp;
}
int main()
{
    int x;
    link *l = new link;
    cin >> x;
    l->data = x;
    l->next = nullptr;
    l->is_printed = false;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        append(l, x);
    }
    link *temp = l;
    while (temp->next)
        temp = temp->next;
    temp->next = l;
    print_loop(l);
}