#include <iostream>
using namespace std;
struct col
{
    int a;
    int b;
};
struct stack2
{
    int size;
    int top; //DIAGRAM
    struct col elements[15];
};
void push2(struct stack2 &s, struct col x)
{
    if (s.top == s.size - 1)
        cerr << "stack2 overflow ";
    else
        s.elements[++s.top] = x;
}
struct col pop2(struct stack2 &s)
{
    struct col x;
    x.a=-1;
    if (s.top == -1)
        return x;
    else
        return s.elements[s.top--];
}
struct col peek2(struct stack2 &s)
{
    struct col x;
    x.a=-1;
    if (s.top == -1)
        return x;
    else
        return s.elements[s.top];
}
void swap(int &s1,int &s2){
    int t = s1;
    s1 = s2;
    s2 = t;
}
int main(){
    struct stack2 s;
    s.top = -1;
    s.size = 15;
    int n = 6;
    int ar[n] = {1,3,2,5,6,4};

    struct col collection;
    collection.a = 0;
    collection.b=5;
    push2(s,collection);
    while(peek2(s).a!=-1){
        struct col collection = pop2(s);
        int l = (collection.a);
        int h = (collection.b);
        if(l<h && l>=0){
            int p = l;
            for (int i = l+1; i <= h; i++)
            {
                if (ar[p] > ar[i])
                {
                    l++;
                    swap(ar[l], ar[i]);
                }
            }
            swap(ar[l], ar[p]);

            struct col c1;
            c1.a = collection.a;
            c1.b = l - 1;

            struct col c2;
            c2.a = l+1;
            c2.b = collection.b;

            push2(s,c1);
            push2(s,c2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i];
    }
    
}