#include <iostream>
using namespace std;
typedef struct node
{
    union
    {
        struct node *sub;
        char next_data;
    };
    int tag;
    struct node *next;
} dir;
void append(dir *d,char x){
    while (d->next)
    {
        d = d->next;
    }
    d->tag = 1;
    d->next_data = x;
    d->next = nullptr;
}
void append(dir *d,dir *next_pointer){
    while (d->next)
    {
        d = d->next;
    }
    d->tag = 0;
    d->next = next_pointer;
}
void print(dir *d){
    if(d){
        if(d->tag==1){
            cout << d->next_data<<" ";
        }
        else
        {
            cout << "{";
            print(d->sub);
            cout << "}";
        }
        d = d->next;
        print(d->next);
    }
}
int main()
{
    char incoming;

    dir *d = new (dir), *temp = new (dir);
    d->next = nullptr;
    d->tag = 1;
    d->next_data = '!';
    while (true)
    {
        cin >> incoming;
        if(incoming=='#')
            break;
        if (incoming == '{')
        {
            temp->tag = 0;

            dir *sub = new (dir);
            while (true)
            {
                cin >> incoming;
                if (incoming == '}')
                {
                    append(sub, nullptr);
                    break;
                }
                append(sub, incoming);
            }
            temp->sub = sub;
            append(d, temp);
        }
        else
        {
            temp->tag = 1;
            temp->next_data = incoming;
            temp->next = nullptr;
            append(d, temp);
        }
        
    }
    print(d);
}