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
void sort(struct queue &q){
        int m = deque(q);
        if(m==-1)
            return;
        int len = q.rear - q.front;
        len = len >= 0 ? len : q.size + len;
        for (int j = 0; j < len; j++)
        {
            int k = deque(q);
            enque(q, m > k ? m : k);
            m = m > k ? k : m;
        }
        sort(q);
        enque(q, m);
}
void sort_q()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 12;

    enque(q, 3);
    enque(q, 6);
    enque(q, 8);
    enque(q, 7);
    enque(q, 1);
    enque(q, 5);
    enque(q, 2);
    enque(q, 4);

    sort(q);
    deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);
    cout << deque(q);

}