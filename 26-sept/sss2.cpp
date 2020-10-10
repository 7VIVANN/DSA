#include <iostream>
using namespace std;
struct node;

struct queue
{
    int front;
    int rear;
    int size;
    struct node *elements[10];
};

typedef struct node
{
    int data;
    struct queue q;
} dir;

void enque(struct queue &q, dir *x)
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
dir *deque(struct queue &q)
{
    if (q.front == -1)
        return nullptr;
    else
    {
        dir *t;
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

void input(dir *d)
{
    int node_data, nodes;

    cin >> node_data;

    dir *temp = new (dir);
    temp->data = node_data;
    temp->q.front = -1;
    temp->q.rear = -1;
    temp->q.size = 0;

    cin >> nodes;
    int i = 0;
    while (i <= nodes)
    {

        enque(d->q, temp);
        input(d);
        i++;
    }
}

int main()
{
    dir *d = new dir;
    int data, nodes;
    cin >> data >> nodes;

    d->data = data;
    (d->q).front = -1;
    (d->q).rear = -1;
    (d->q).size = 0;

    enque((d->q), nullptr);

    input(d);
}
