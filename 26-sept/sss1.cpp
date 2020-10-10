/*SSS1 26/9/20 */
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
        cout << d->node_data << " ";
        if (d->sub)
            print_children(d->sub);
        d = d->next_node;
    }
}
void bubble_dir(dir *d){
    int node_head = d->node_data;
    int child_data=-1;

    subdir *chain;
    chain = d->sub;
    while (chain)
    {
        child_data = chain->child_data;
        if(node_head>child_data){
            chain->child_data = node_head;
            d->node_data = child_data;
            node_head = child_data;
            child_data = chain->child_data;
        }
        chain = chain->next_child;
    }
}
void bubble_subdir(dir *d){
    subdir *chain,*sub_chain;
    chain = d->sub;
    while (chain)
    {
        sub_chain = chain;
        int node_head = chain->child_data;
        int child_data;

        while (sub_chain)
        {
            child_data = sub_chain->child_data;
            if (node_head > child_data)
            {
                sub_chain->child_data = node_head;
                chain->child_data = child_data;
                node_head = child_data;
            }
            sub_chain = sub_chain->next_child;
        }
        chain = chain->next_child;
    }
    
}
void bubble_sort(dir *d){
    bubble_dir(d);
    bubble_subdir(d);
}

subdir* get_last_child(dir *d){
    int child_data = -1;

    subdir *chain;
    chain = d->sub;
    while (chain)
    { 
        child_data = chain->child_data;
        if(!chain->next_child)
            break;
        chain = chain->next_child;
    }
    return chain;
}
void sort_list(dir *d)
{
    while (d->next_node)
    {
        bubble_sort(d);
        int last_child = get_last_child(d)->child_data;
        int next_node_head = d->next_node->node_data;
        if(last_child>next_node_head){
            d->next_node->node_data = last_child;
            get_last_child(d)->child_data = next_node_head;
            bubble_sort(d);
        }
        d = d->next_node;
        
    }
}

int main()
{

    //assuming atleast value in the ML
    int option, value;
    cin >> value;

    dir *ML, *temp;
    ML = new (dir);
    ML->node_data = value;
    ML->sub = nullptr;
    ML->next_node = nullptr;

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
    sort_list(ML);
    flatten_print(ML);
}