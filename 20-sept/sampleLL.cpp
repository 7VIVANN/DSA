#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};

void print(struct node* l){
    while (l->next)
    {
        cout << l->data << " ";
        l = l->next;
    }
    cout << l->data;
}
void print_rev(struct node* l){
    int x = l->data;
    if(l->next)
    {
        l = l->next;
        print_rev(l);
        
    }
    cout << x << " ";
}
void add_end(struct node* &L,int x){
    struct node *l;
    l = L;
    while (l->next)
    {
        l = l->next;
    }
    struct node *t;
    t = new (struct node);
    t->data = x;
    t->next = nullptr;
    l->next = t;
}
void add_front(struct node* &L,int x){
     if(L->next){
         struct node *T;
         T = new (struct node);
         T->data = x;
         T->next = L;
         L = T;
     }
     else
     {
         cout << "underflow";
     }
     
}
void delete_front(struct node* &L){
    if(L->next)
        L = L->next;
    else
        cout << "underflow";
}
void delete_end(struct node* &L){
    struct node *l;
    l = L;
    while (l->next)
    {
        if(!l->next->next){
            l->next = nullptr;
            break;
        }
        l = l->next;
    }
}
void insert(struct node* &L,int pos,int val){
    //inserts after pos+1 index
    struct node *l;
    l = L;
    int present = 0;
    while(pos!=present){
        l = l->next;
        present++;
    }
    struct node *T;
    T = new (struct node);
    T->data = val;
    T->next = l->next;
    l->next = T;
}
void replace(struct node* L,int pos,int val){
    //replaces  pos position element .For pos index present = 2;
    struct node *l;
    l = L;
    int present = 1;
    while (pos != present)
    {
        l = l->next;
        present++;
    }
    l->data = val;
}
void find(struct node* l,int k){
    while (l->next)
    {
        if(k==l->data)
        {
            cout << 1;
            return;
        }
        l = l->next;
    }
    if(l->data==k)
        cout << 1;
    else
        cout << 0;
}
void number_of_elements(struct node* l){
    int odd_counter = 0;
    int even_counter = 0;
    while(l->next){
        if(l->data %2==0)
            even_counter++;
        else
            odd_counter++;
        l = l->next;
    }
    if (l->data % 2 == 0)
        even_counter++;
    else
        odd_counter++;
    cout << odd_counter;
    cout << "\n";
    cout << even_counter;
}
int get_length(struct node* l){
    int len = 0;
    while(l->next){
        len++;
        l = l->next;
    }
    return len+1;//pre for first element post for last element
}
int get_max(struct node* l){
    int m = l->data;
    while (l->next)
    {
        l = l->next;
        m = m > l->data ? m : l->data;
    }
    m = m > l->data ? m : l->data;
    return m;
}
int get_min(struct node *l)
{
    int m = l->data;
    while (l->next)
    {
        l = l->next;
        m = m < l->data ? m : l->data;
    }
    m = m < l->data ? m : l->data;
    return m;
}
int get_middle(struct node* sl){
    struct node *fast_pointer;
    fast_pointer=sl;
    while(fast_pointer->next){
        fast_pointer = fast_pointer->next;
        sl = sl->next;
        if(fast_pointer->next)
            fast_pointer = fast_pointer->next;
        else
            break;
    }
    return sl->data;
}
int find_even(struct node *l)
{
    while (l->next)
    {
        if (l->data % 2 == 0)
            return 1;
        l = l->next;
    }
    if (l->data % 2 == 0)
        return 1;
    else
        return -1;
}

int main(){
    int n;

    struct node *L;
    L = new (struct node);

    int x;
    cin >> x;
    L->data = x;
    L->next = nullptr;

    while(true){
        cin >> x;
        if(x==-1)
            break;
        add_end(L, x);
    }
    struct node *t;
    t = L->next;
    cout << find_even(t);
}