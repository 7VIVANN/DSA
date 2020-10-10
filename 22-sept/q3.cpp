#include <iostream>
using namespace std;
union u
{
    int i;
    char c;
    float f;
    bool b;
};
struct generic_stack
{
    int size;
    int top; //DIAGRAM
    union u elements[10];
    int tag[10];
};
void generic_push(struct generic_stack &s, union u &x, int t)
{
    if (s.top == s.size - 1)
        cerr << "generic_stack overflow ";
    else
    {
        switch (t)
        {
        case 0:
            s.elements[++s.top].i = x.i;
            s.tag[s.top] = t;
            break;
        case 1:
            s.elements[++s.top].c = x.c;
            s.tag[s.top] = t;
            break;
        case 2:
            s.elements[++s.top].f = x.f;
            s.tag[s.top] = t;
            break;
        case 3:
            s.elements[++s.top].b = x.b;
            s.tag[s.top] = t;
            break;
        default:
            break;
        }
    }
}
union u generic_pop(struct generic_stack &s)
{
    if (s.top == -1)
        cerr << "generic_stack empty ";
    else
    {
        return s.elements[s.top--];
    }
}
union u generic_peek(struct generic_stack &s)
{
    if (s.top == -1)
        cerr << "generic_stack empty ";
    else
    {
        return s.elements[s.top];
    }
}

struct queue
{
    int front;
    int rear;
    int size;
    struct generic_stack elements[20];
};
void enque(struct queue &q, struct generic_stack gs)
{
    if (q.rear + 1 % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
         q.elements[q.rear] = gs;
        q.rear = (q.rear + 1) % q.size;
    }
    else
    {
        q.elements[q.rear] = gs;
        q.rear = (q.rear + 1) % q.size;
    }
}
struct generic_stack deque(struct queue &q)
{
    if (q.front == -1)
        return nullptr;
    else
    {
        struct generic_stack t;
        if (q.front == q.rear)
        {
            t = generic_pop(q.elements[q.front]);
            q.rear = -1;
            q.front = -1;
        }
        else
        {
            t = generic_pop(q.elements[q.front]);
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}

int main(){
    struct queue q;
    q.rear = -1;
    q.front = -1;
    q.size = 10;

    int tag=0;
    union u x;
    struct generic_stack gs;

    cout << "to exit enqueqing a particular element insert tag as -1\n To exit the input as a whole insert tag as -2\n";

    while (true)
    {
        cin >> tag;
        if(tag==-2)
            break;
        gs.size = 10;
        gs.top = -1;
        while (true)
        {
            switch (tag)
            {
            case 1:
                cin >> x.i;
                break;

            case 2:
                cin >> x.c;
                break;

            case 3:
                cin >> x.f;
                break;

            case 4:
                cin >> x.b;
                break;

            default:
                break;
            }

            gs.tag = tag;
            generic_push(gs, x, tag);
            cin >> tag;
            if(tag==-1)
                break;
        }
        enque(q,gs);
    }

    
}
