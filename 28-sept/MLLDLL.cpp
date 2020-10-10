#include <iostream>
using namespace std;
typedef struct dlnode
{
    struct dlnode *left;
    int data;
    struct dlnode *right;
} dlink;
dlink *d1;
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
void print(dlink *d)
{
    if (d)
    {
        while (d->right)
        {
            cout << d->data << " ";
            d = d->right;
        }
        cout << d->data << " ";
    }
}

typedef struct child
{
    int child_data;
    struct child *next_child;
} subdir;
typedef struct node
{
    int node_data;
    subdir *sub;
    struct node *next_node;
} dir;
void link_children(dir *d, int value)
{
    subdir *temp_child;
    temp_child = new (subdir);
    temp_child->child_data = value;
    temp_child->next_child = nullptr;

    subdir *chain;
    chain = d->sub;
    if (!chain)
    {
        d->sub = temp_child;
    }
    else
    {
        while (chain->next_child)
        {
            chain = chain->next_child;
        }
        chain->next_child = temp_child;
    }
}
void link_nodes(dir *d, int value)
{
    dir *temp_node;
    temp_node = new (dir);
    temp_node->node_data = value;
    temp_node->sub = nullptr;
    temp_node->next_node = nullptr;

    while (d->next_node)
    {
        d = d->next_node;
    }
    d->next_node = temp_node;
}
void input(dir *&ML)
{
    int option, value;

    dir *temp;
    while (value != -2)
    {
        cin >> option;
        switch (option)
        {
        case 1:
            temp = ML;
            while (temp->next_node)
            {
                temp = temp->next_node;
            }
            while (true)
            {
                cin >> value;
                if (value == -1)
                    break;
                link_children(temp, value);
            }
            cin >> value;
            if (value != 0)
            {
                link_nodes(ML, value);
            }
            break;
        case 0:
            cin >> value;
            if (value < 0)
                continue;
            link_nodes(ML, value);
            break;
        }
    }
}
void sort_ML(int x)
{
    dlink *d2 = new dlink;
    d2 = nullptr;
    int y =x+1;
    while (true)
    {
        y = pop_back(d1);
        if(y==-1 || x>y)
            break;
        append(d2, y);
    }
    if (y != -1)
        append(d1, y);
    append(d1, x);
    

    y = pop_back(d2);
    while (y!=-1)
    {
        append(d1, y);
        y = pop_back(d2);
    }
}
void print_children(subdir *chain)
{
    while (chain)
    {
        sort_ML(chain->child_data);
        chain = chain->next_child;
    }
}
void sort_DLL(dir *d)
{
    while (d)
    {
        sort_ML(d->node_data);
        if (d->sub)
        {
            if (d->sub)
            {
                print_children(d->sub);
            }
        }
        d = d->next_node;
    }
}

int main()
{
    d1 = nullptr;

    //assuming atleast value in the ML
    int value;
    cin >> value;
    dir *ML;
    ML = new (dir);
    ML->node_data = value;
    ML->sub = nullptr;
    ML->next_node = nullptr;

    input(ML);
    sort_DLL
(ML);
    print(d1);
}
