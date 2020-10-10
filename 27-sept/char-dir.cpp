#include <iostream>
using namespace std;

typedef struct child
{
    char child_data;
    struct child *link;
} subdir;
typedef struct node
{
    char node_data;
    subdir *link;
    struct node *next;
} dir;

//to print the actual directory like structure uncomment the cout statements .
void print_subdir(subdir *sd)
{
    cout << sd->child_data << " ";
    // cout<<"\n";

    if (sd->link)
    {
        // cout << "---";
        print_subdir(sd->link);
    }
}
void print_dir(dir *d)
{
    cout << d->node_data << " ";
    // cout<<"\n";

    if (d->link)
    {
        // cout << "---";
        print_subdir(d->link);
    }

    if (d->next)
        print_dir(d->next);
}
void input_subdir(subdir *sd, char x)
{
    sd->child_data = x;
    sd->link = nullptr;
}
void input(dir *d, int option, char x)
{
    switch (option)
    {
    case 0:
        dir *temp_dir;
        temp_dir = new (dir);
        temp_dir->node_data = x;
        temp_dir->link = nullptr;
        temp_dir->next = nullptr;
        while (d->next)
        {
            d = d->next;
        }
        d->next = temp_dir;
        break;

    case -1:
        subdir *temp_subdir;
        temp_subdir = new (subdir);
        temp_subdir->child_data = x;
        temp_subdir->link = nullptr;
        while (d->next)
        {
            d = d->next;
        }
        if (d->link)
        {
            subdir *temp = d->link;
            if (temp)
            {
                while (temp->link)
                {
                    temp = temp->link;
                }
                temp->link = temp_subdir;
            }
            else
                temp->link = temp_subdir;
        }
        else
            d->link = temp_subdir;

        break;

    default:
        return;
    }
}

int main()
{
    cout << "syntax:(option) (value)\n [option]:\n\t{0 for entering in root directory}\n\t{-1 to attach to the tail of the previous element entered in root directory}\n\t{-2 exit}\n";

    int option = -2;
    char value = '!';

    dir *d;
    d = new (dir);
    cin >> option;
    cin >> value;
    d->node_data = value;
    d->next = nullptr;
    d->link = nullptr;

    while (true)
    {
        cin >> option;
        if (option == -2)
            break;
        cin >> value;
        input(d, option, value);
    }
    print_dir(d);
}