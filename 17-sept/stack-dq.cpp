#include <iostream>
using namespace std;
struct dequeue
{
    int front;
    int rear;
    int size;
    int elements[20];
};
void push_back(struct dequeue &q, int x)
{
    if (q.rear + 1 % q.size == q.front)
        cout <<"OVERFLOW" ;
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = (q.rear + 1) % q.size;
        q.elements[q.rear] = x;
    }
    else
    {
        q.rear = (q.rear + 1) % q.size;
        q.elements[q.rear] = x;
    }
}
void push_front(struct dequeue &q, int x)
{
    if (q.rear + 1 % q.size == q.front)
        cout <<"OVERFLOW" ;

    else
    {
        q.front--;
        q.front = q.front < 0 ? q.front + q.size - 1 : q.front;
        q.elements[q.front] = x;
    }
}
int pop_front(struct dequeue &q)
{
    if (q.front == -1)
        return -1;
    else
    {
        int t;
        if (q.front == q.rear)
        {
            t = q.elements[q.front];
            q.rear = -1;
            q.front = -1;
        }
        else
        {
            t = q.elements[q.front];
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
int pop_back(struct dequeue &q)
{
    int t;
    if (q.front == -1)
    {
        return -1;
    }
    else
    {
        int t;
        if (q.front == q.rear && q.front == 0)
        {
            t = q.elements[q.rear];
            q.rear = -1;
            q.front = -1;
        }
        else
        {
            t = q.elements[q.rear];
            q.rear--;
        }
        return t;
    }
}
struct stack{
    struct dequeue q;
};
void push(struct stack &s,int x){
    push_back(s.q, x);
}
int pop(struct stack &s){
   return pop_back(s.q);
}
int main()
{
    struct stack s;
    s.q.front = -1;
    s.q.rear = -1;
    s.q.size = 10;
    push(s, 10);
    cout<<pop(s);
}