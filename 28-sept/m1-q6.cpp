#include <iostream>
using namespace std;
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

struct queue
{
    int front;
    int rear;
    int size;
    dir *elements[10];
};

void enque(struct queue &q, dir *x)
{
    if (q.rear + 1 % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
        q.elements[q.rear] = x;
        q.rear = (q.rear + 1) % q.size;
    }
    else
    {
        q.elements[q.rear] = x;
        q.rear = (q.rear + 1) % q.size;
    }
}
dir *deque(struct queue &q)
{
    if (q.front == -1)
        return nullptr;
    else
    {
        dir *t;
        if (q.front == q.rear)
        {
            t = q.elements[q.front];
            q.rear = -1;
            q.front = -1;
        }
        else
        {
            t = q.elements[q.front];
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
//queue of subdirectories while printing length first
queue dir_lister;
void swap(dir *ML){

    if(ML==nullptr)
        return;
    dir *k = ML->next_node;
    subdir *l = ML->sub;

    ML->sub = nullptr;

    while (k)
    {
        link_children(ML, k->node_data);
        k = k->next_node;
    }
    ML->next_node = nullptr;

    while (l)
    {
        link_nodes(ML, l->child_data);
        l = l->next_child;
    }

    swap(ML->next_node);
}
void print_children(subdir *chain)
{
    while (chain)
    {
        cout << chain->child_data << " ";
        chain = chain->next_child;
    }
}
void flatten_print(dir *d)
{
    while (d)
    {
        cout << "( ";
        cout << d->node_data << " ";
        if (d->sub)
        {
            if (d->sub)
            {
                print_children(d->sub);
                // cout << ") ( ";
            }
        }
        cout << ") ";
        d = d->next_node;
    }
}

void print_dirs_length_first(dir *d)
{
    while (d)
    {
        cout << d->node_data << " ";
        if (d->sub)
        {
            enque(dir_lister, d->next_node);
        }
        d = d->next_node;
    }
    d = deque(dir_lister);
    while (d)
    {
        print_dirs_length_first(d);
        d = deque(dir_lister);
    }
}
int main(){
    dir *ML = new dir;
    input(ML);
    swap(ML);
    print_dirs_length_first(ML);
    flatten_print(ML);
}