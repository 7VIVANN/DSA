#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} link;
int default_values[2] = {0, 0};
int sum[2]; //a and b


void append(link *&L, int data)
{
    link *temp = new link, *l;
    temp->data = data;
    temp->next = nullptr;
    l = L;
    while (l->next)
    {
        l = l->next;
    }
    l->next = temp;
}
void input(link *&l)
{
    int x;
    cin >> x;
    l->data = x;
    l->next = nullptr;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        append(l, x);
    }
}
void print(link *l)
{
    while (l->next)
    {
        cout << l->data;
        l = l->next;
    }
    cout << l->data;
}
int flip(int x){
    return x ^ 1;
}
int choose(link *l1, link *l2, int pno)
{
    int current_values[2] = {sum[0], sum[1]};

    if (l1 && l2)
    {
        link *t1 = l1, *t2 = l2;

        sum[pno] += t1->data;
        t1 = t1->next;
        if (choose(t1, t2,flip(pno)) == 1)
            return 0;

        sum[pno] =current_values[pno];
        sum[flip(pno)] = current_values[flip(pno)];

        t1 = l1, t2 = l2;
        
        sum[pno] += t2->data;
        t2 = t2->next;
        if (choose(t1, t2, flip(pno)) == 1)
            return 1;

        return 0;
    }
    else if (l1)
    {
        sum[pno] += l1->data;
        l1 = l1->next;
        return 1 * choose(l1, l2, flip(pno));
    }
    else if (l2)
    {
        sum[pno] += l2->data;
        l2 = l2->next;
        return 1 * choose(l1, l2, flip(pno));
    }
    else
    {
        sum[0] = default_values[0];
        sum[1] = default_values[1];
        
        return (current_values[1] > current_values[0]) ? 0 : 1; 
    }

}
//recurse and evaluate the sum(a),sum(b) for each branch

// A strategy fails if atleast once sum(a)<sum(b)

    //choose returns an event
    //all othr events return 1*func
    //event e
    //if(sum(a))<sum(b))
        // return 0;
    //else
        // return 1;


int main()
{
    link *l1 = new link, *l2 = new link;
    input(l1);
    input(l2);

    sum[0] = default_values[0];
    sum[1] = default_values[1];

    cout << choose(l1, l2, 0);
}