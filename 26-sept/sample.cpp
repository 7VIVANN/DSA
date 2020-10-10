#include <iostream>
typedef struct node{
    int data;
    struct node *next;
}node;

int main(){
    node *n1;
    n1 = new (node);
    n1->data = 10;
    n1->next = nullptr;

    node *n2;
    n2->data = 20;
    n2->next = n1;

    printf("%d\t%d", n2->data,n2->next->data);
    
}
