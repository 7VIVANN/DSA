/* |a| | | -> |b| | | -> |f| | | -> 
             |
             ^
             | c| | | -> |d| | |-> |e| | |   */
/* 
typedef struct node{

    int data;
    struct node *subdir; //null for empty subdir
    struct node *next;

} dir;

 */
/* void print_ml(dir* d){
    while (d->next)
    {
        if(d->tag == 0){
            cout << d->subdir.data << " ";
        }
        else
        {
            print_ml(d->subdir.link);
        }
        cout << "\n\t";
        d = d->next;
    }

    if (d->tag == 0)
    {
        cout << d->subdir.data << " ";
    }
    else
    {
        print_ml(d->subdir.link);
    }
} */
#include <iostream>
using namespace std;
int main(){
    int a = 10, b = 12, c = 13;
    if (a==b)
    {
        cout << "nono";
    }
    int d;
    cin >> d;
    else
    {
        cout << "wowo";
    }
    
}