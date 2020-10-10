#include <iostream>
using namespace std;
void call_by_value(int a , int b){
    int t;
    t = a;
    a = b;
    b = t;
    cout<<"\nRESULT OF CALL BY VALUE  a :" << a <<" b: "<< b;
}
void call_by_ref(int &a, int &b)//aliases
{
    int t;
    t = a;
    a = b;
    b = t;
    cout<<"\nRESULT OF CALL BY REFERENCE( ALIAS ) : a: "<< a <<" b: "<< b;
}
void call_by_pointer(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    cout << "\nRESULT OF CALL BY POINTER  a :" << *a <<" b: "<< *b;
}
void pointer_and_value(int *a,int b){
    int *t; //temp is a pointer
    t = a;
    *a = b;
    b = *t;
    cout << "\nRESULT OF A POINTER AND A VALUE WITH TEMP AS POINTER   a :" << *a <<" b: "<< b;
    //CONCLUSION: this is not going to swap the values because (0)t points to a ,(1)a takes value of b, thus t takes value of b,(2) finally b takes value of t which infact is the original value of b
}
void corrected_pointer_and_value(int *a,int b){

}
void value_and_pointer(int *a, int b)
{
    int t; //temp is a value
    t = b;
    b = *a;
    *a = t;
    cout << "\nRESULT OF A POINTER AND A VALUE WITH TEMP AS VALUE   a :" << *a <<" b: "<< b;
}
void pointer_and_ref(int *a, int &b)
{
    int *t; //temp is a pointer
    t = a;
    *a = b;
    b = *t;
    cout << "\nRESULT OF A POINTER AND A REFERENCE WITH TEMP AS POINTER   a :" << *a <<" b: "<< b;
    //CONCLUSION: this is not going to swap the values because (0)t points to a ,(1)a takes value of b, thus t takes value of b,(2) finally b takes value of t which infact is the original value of b
}
void ref_and_pointer(int *a, int &b)
{
    int t; //temp is a value
    t = b;
    b = *a;
    *a = t;
    cout << "\nRESULT OF A POINTER AND A VALUE WITH TEMP AS VALUE   a :" << *a <<" b: "<< b;
}
void ref_and_value(int &a, int b) //aliases
{
    int t;
    t = a;
    a = b;
    b = t;
    cout << "\nRESULT OF CALL BY REFERENCE AND VALUE : a: " << a <<" b: "<< b;
}
int main(){
    int p = 5;
    int b = 3;
    call_by_value(p, b);
    p = 5;
    b = 3;
    call_by_ref(p, b);
    p = 5;
    b = 3;
    call_by_pointer(&p, &b);
    p = 5;
    b = 3;
    pointer_and_value(&p, b);
    p = 5;
    b = 3;
    value_and_pointer(&p, b);
    p = 5;
    b = 3;
    pointer_and_ref(&p, b);
    p = 5;
    b = 3;
    ref_and_pointer(&p, b);
    p = 5;
    b = 3;
    ref_and_value(p,b);
}