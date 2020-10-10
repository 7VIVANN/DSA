#include <iostream>
using namespace std;
typedef struct node{
    int *ar;
    struct node *next;
} link;
link* find(int a , link* l){
    while (true)
    {
        if (l->ar[0] == a)
        {
            return l;
        }
        if (!l->next)
        {
            return -1;
        }    
    }
}
void insert_into_array(link *l)

int main(){
       
}