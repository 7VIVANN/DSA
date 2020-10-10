#include <iostream>
using namespace std;
typedef struct node{
    int i;
    char c;
    struct node *next;
}link;
void append(int i,char c,link *l){
    link *temp = new link;
    temp->i = i;
    temp->c = c;
    temp->next = nullptr;
    while(l->next){
        l = l->next;
    }
    l->next = temp;
}
void print(link *l){
    while (l)
    {
        cout << l->c << " " << l->i << " ";
        l = l->next;
    }
    
}
int main(){
    int i=0;
    char c;
   

    link *l1 = new link;
    l1->i = -1;
    l1->c = '!';
    l1->next = nullptr;
    
    while (true)
    {
        cin >> c >> i;
        if(i==-1)
            break;
        append(i, c, l1);
    }
    l1 = l1->next;

    link *l1 = new link;
    l1->i = -1;
    l1->c = '!';
    l1->next = nullptr;

    while (true)
    {
        cin >> c >> i;
        if (i == -1)
            break;
        append(i, c, l2);
    }
    l2 = l2->next;

    link *l3 = new link;
    l3->i = -1;
    l3->c = '!';
    l3->next = nullptr;

    while (true)
    {
        cin >> c >> i;
        if (i == -1)
            break;
        append(i, c, l3);
    }
    l3 = l3->next;

    print(l1);
    print(l2);
    print(l3);
}