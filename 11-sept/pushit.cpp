#include <iostream>
#include <string>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[50];
};

void push(struct stack &s, int x)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        s.elements[++s.top] = x;
}
int pop(struct stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top--];
}
int peek(struct stack &s)
{
    if (s.top == -1)
        return -1;
    else
        return s.elements[s.top];
}
int main(){
    int n = 5;
    int ar[n];
	struct stack ps;
	struct stack pp;
	ps.top=-1;
	pp.top=-1;
	ps. size=0;
	pp.size=0;
	for(int i=0;i<n;i++){
	 cin>>ar[0];
	}
	int j=0;
    int pos = 0;
    for(int i=1;i<=n;i++){
        if (i!=ar[pos])
        {
            push(ps, i);
        }
        else if(peek(pp)==ar[pos]){
            pop(ps);
            push(pp, ar[pos++]);
        }
        else {
            push(pp, ar[pos++]);
        }
        
	}
    int ex = 0;
    for(int i=n;i>0;i--){
	 if(ar[i]!=pop(pp)){
         cout << 0;
         ex++;
         break;
     }
	}
    if(ex==1)
        cout << 1;
}