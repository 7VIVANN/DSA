#include <iostream>
using namespace std;
struct queue
{
    int front;
    int rear;
    int size;
    int elements[20];
};
void enque(struct queue &q, int x)
{
    if (q.rear + 1 % q.size == q.front)
        cout <<"overflow" ;
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
int deque(struct queue &q)
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
            ;
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}

int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 10;
    enque(q, 10);
    enque(q, 12);
    enque(q, 10);
    enque(q, 12);
    enque(q, 10);
    enque(q, 12);
    enque(q, 10);
    enque(q, 12);
    int k = deque(q);
    while(k!=-1){
        cout << k;
        k = deque(q);
    }
   
}