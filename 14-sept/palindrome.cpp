#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top; //DIAGRAM
    char elements[50];
};

void push(struct stack &s, char x)
{
    if (s.top == s.size - 1)
        cerr << "stack overflow ";
    else
        s.elements[++s.top] = x;
}
char pop(struct stack &s)
{
    if (s.top == -1)
        return '!';
    else
        return s.elements[s.top--];
}
char peek(struct stack &s)
{
    if (s.top == -1)
        return '!';
    else
        return s.elements[s.top];
}
struct queue
{
    int front;
    int rear;
    int size;
    char elements[20];
};
void enque(struct queue &q, char x)
{
    if ((q.rear + 1) % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
        q.elements[q.rear] = x;
        q.rear = (q.rear + 1) % q.size;
    }
    else
    {
        q.elements[q.rear] = x;
        q.rear = (q.rear + 1) % q.size;
    }
}
char deque(struct queue &q)
{
    if (q.front == -1)
        return '!';
    else
    {
        char t;
        if (q.front == q.rear)
        {
            t = q.elements[q.front];
            q.rear = -1;
            q.front = -1;
        }
        else
        {
            t = q.elements[q.front];
            ;
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
int main(){
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 20;
    struct stack s;
    s.size = 20;
    s.top = -1;
    char x = ' ';
    while(x!='#'){
        cin >> x;
        if(x=='#')
            break;
        enque(q, x);
    }
    char t = deque(q);
    int i = 0;
    while (t != '!')
    {
        push(s, t);
        i++;
        t = deque(q);
    }
    s.top = i-1;
    while (peek(s)!='!')
    {        
        enque(q, pop(s));
    }
    s.top = i - 1;
    bool con = true;
    while(con && peek(s)!='!'){
        con = deque(q) == pop(s);
    }
    cout << con ? "1" : "0";
}