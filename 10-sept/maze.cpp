#include <iostream>
#include <string>
using namespace std;
int ex, ey;
int a = 8, b = 8;
int ar[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};
int err[] = {-1, -1};
struct stack
{
    int size;
    int top; //DIAGRAM
    int elements[20][2];
};

void push(struct stack &s, int x,int y)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
      {
          s.elements[++s.top][0] =x;
          s.elements[s.top][1] = y;
      }
}
int* pop(struct stack &s)
{
    if (s.top == -1)
        return err;
    else
        return s.elements[s.top--];
}
int* peek(struct stack &s)
{
    if (s.top == -1)
        return err;
    else
        return s.elements[s.top];
}

void solve(int x,int y,struct stack &s){ 
    if(x>a||x<=0||y>b||y<0)
        return;
    if(ar[x+1][y]==1)
    {
        push(s, x + 1, y);
        solve(x+1,y,s);
        if(peek(s)[0]==ex&& peek(s)[1]==ey)
            return;
        int *ptr=pop(s);
    }
    if (ar[x][y+1] == 1)
    {
        push(s, x, y+1);
        solve(x, y+1, s);
        if (peek(s)[0] == ex && peek(s)[1] == ey)
            return;
        int *ptr=pop(s);
    }
    return;
}
int main()
{
    struct stack s;
    s.top = -1;
    s.size = 20;
    int sx ,sy;
    cin >> sx >> sy;
    cin>>ex>>ey;
    push(s, 1, 1);
    solve(1, 1, s);
    if (peek(s)[0] == ex && peek(s)[1] == ey)
        cout<<1;
    else
    {
        cout << 0;
    }
    
}