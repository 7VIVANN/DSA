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
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
void print(struct queue q){
    int k = deque(q);
    while(k!=-1){
        cout << k;
        k = deque(q);
    }
}
void rotate(){
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 10;

    struct queue temp;
    temp.front = -1;
    temp.rear = -1;
    temp.size = 10;

    int n = 5;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        enque(q, x);
        enque(temp, x);
    }

    int len = q.rear - q.front;
    len = len >= 0 ? len : len + q.size;

    for (int i = 0; i < n; i++)
    {
        struct queue q1;
        struct queue q2;

        q1.front = -1;
        q1.rear = -1;
        q1.size = 10;

        q2.front = -1;
        q2.rear = -1;
        q2.size = 10;

        int k = deque(q);
        while (k != -1){
            enque(temp, k);
            k = deque(q);
        }

        for (int j = 0; j < i; j++)
        {
            enque(q1, deque(temp));
        }
        for (int j = i; j < n; j++)
        {
            enque(q2, deque(temp));
        }

        for (int j = 0; j < i; j++)
        {
            enque(q1, deque(q1));
            
            for (int l = 0; l < n-i; l++)
            {
                enque(q2, deque(q2));

                print(q1);
                print(q2);

                cout << endl; 
            }
            
        }
        
    }
    
}
int main(){
    rotate();
}