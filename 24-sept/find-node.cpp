#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
} link;
void print(link* l){
    if(l->next)
    {
        while (l->next)
        {
            cout << l->data << " ";
            l = l->next;
        }
        
    }
    cout << l->data << " ";
}
link* get_n(link *l,int n){
    i = 1;
    while (l->next)
    {
        if(i==n)
            break;
        i++;
        l = l->next;
    }
    return l;
}
int main(){
       
}