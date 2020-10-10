#include <iostream>
using namespace std;
union u{
    int a;
    char b;
};
struct queue
{
    int front;
    int rear;
    int size;
    union u elements[20];
    int tag[20];
};
void enque(struct queue &q, int x)
{
    if (q.rear + 1 % q.size == q.front)
        cout << ;
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
}