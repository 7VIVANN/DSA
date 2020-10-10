#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
    struct node *random;
} link;
link *find(link *l, int to_find)
{
    while (l)
    {
        if (l->data == to_find)
            return l;
        l = l->next;
    }
    return nullptr;
}
void append(link *l, int node_data, int next_node, int random_node)
{
    link *next, *random = find(l, random_node);

    link *temp = new (link);
    temp->data = node_data;
    temp->next = next;
    temp->random = random;

    while (l->next)
        l = l->next;
    l->next = temp;
}
void print(link *l)
{
    cout << l->data << " "; //print the data value

    link *copy = l; //retain the current node
    if (l->next)
        print(l->next); //recursively call the print function on the next node if next node exits
    cout << endl;

    copy = l;   
    if (l->random) //recusrsively call the print function on the random node if random node exists
        print(l->random);
    cout << endl;
}
int main()
{
    link *l = new link;

    int node_data, next_node = -1, random_node = -1;

    while (true)
    {
        cin >> node_data >> next_node >> random_node;
        if (next_node == 0 && random_node == 0)
            break;
        append(l, node_data, next_node, random_node);
    }

    print(l);
}