#include <iostream>
#include <string>
using namespace std;
struct n_digits_stack{
    int size;
    int top;//DIAGRAM
    int elements[10];
};

void n_digits_push(struct n_digits_stack &s, int x)
{
    if(s.top == s.size - 1)
        cerr << "n_digits_stack overflow "; 
    else 
        s.elements[++s.top] = x;
}
int n_digits_pop(struct n_digits_stack &s){
    if(s.top == -1)
        return -1;
    else
        return s.elements[s.top--];
}
int n_digits_peek(struct n_digits_stack &s)
{
    if(s.top == -1)
        return -1;
    else 
        return  s.elements[s.top];
}
void n_digits()
{
    //APPLICATIONS  
    //STORING DIGITS
    struct n_digits_stack s1;
    s1.top = -1;
    s1.size = 10;
    int n = 7453;
    int d;
    while(n>0){
        d = n%10;
        n = n / 10;
        n_digits_push(s1, d);
    }
    
    while(n_digits_peek(s1)!=-1){
        cout<<n_digits_pop(s1);
    }
}
int main(){
    n_digits();
}