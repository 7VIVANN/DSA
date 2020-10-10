#include <iostream>
using namespace std;

typedef struct node
{
    int tag;
    union  
    {
        char data;
        struct node *link;
    } subdir;
    struct node *next;
} dir;

void print(dir *d)
{
    if (d->next)
    {
        if (d->tag == 0)
        {
            cout << d->subdir.data << " ";
        }
        else
        {
            cout << "(";
            print_ml(d->subdir.link);
        }
        cout << "\n\t";
        d = d->next; 
        print_ml(d);
        cout << ")";
    }

}
void input(dir* d){

}


int main(){
    cout << "syntax : ";
}