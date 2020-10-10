/* MULTI LEVEL Q2 9/26/20   */

#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *subdir;
    struct node *next;
} dir;
struct stack
{
    int size;
    int top;
    dir *elements[10];
};
struct queue
{
    int front;
    int rear;
    int size;
    dir* elements[10];
};

void enque(struct queue &q, dir* x)
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
dir* deque(struct queue &q)
{
    if (q.front == -1)
        return nullptr;
    else
    {
        dir* t;
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
//queue of subdirectories while printing length first
queue dir_lister;
void push(struct stack &s, dir *x)
{
    if (s.top == s.size - 1)
        cerr << "stack	overflow	";
    else
        s.elements[++s.top] = x;
}
dir *pop(struct stack &s)
{
    if (s.top == -1)
        return nullptr;
    else
        return s.elements[s.top--];
}
dir *peek(struct stack &s)
{
    if (s.top == -1)
        return nullptr;
    else
        return s.elements[s.top];
}
//stack of pointers to store the parent directory before going in-depth
struct stack bucket;
void print_dirs_depth_first(dir *d)
{
    if (d)
    {
        cout << d->data << " ";
        if (d->subdir)
        {
            print_dirs_depth_first(d->subdir);
        }
        print_dirs_depth_first(d->next);
    }
}
void print_dirs_length_first(dir *d)
{
    while (d)
    {
        cout << d->data << " ";
        if (d->subdir)
        {
            enque(dir_lister, d->subdir);
        }
        d = d->next;
    }
    d = deque(dir_lister);
    while (d)
    {
        print_dirs_length_first(d);
        d = deque(dir_lister);
    }
}
void same_level_link(dir *d, int value)
{
    dir *temp;
    temp = new (dir);
    temp->data = value;
    temp->next = nullptr;
    temp->subdir = nullptr;
    while (d->next)
    {
        d = d->next;
    }

    d->next = temp;
}
void depth_level_link(dir *d, int value)
{
    dir *temp;
    temp = new (dir);
    temp->data = value;
    temp->next = nullptr;
    temp->subdir = nullptr;
    while (d->next)
    {
        d = d->next;
    }
    d->subdir = temp;
}
dir *input(int option, int value, dir *d)
{
    switch (option)
    {
    case 1:
        depth_level_link(d, value); /* allot a sub diretory */
        push(bucket, d);            /* depth-level-increases, push it into the stack; */
        while (d->next)
        {
            d = d->next;
        }

        d = d->subdir; /* change the state to the sub directory */
        return d;
    case 0:
        same_level_link(d, value);
        return d;
    case -1:
        if (peek(bucket))
            d = pop(bucket);
        else
            d = nullptr;
        return d;
    default:
        return nullptr;
    }
}

int main()
{
    bucket.size = 10;
    bucket.top = -1;

    dir_lister.front = -1;
    dir_lister.rear = -1;
    dir_lister.size = 10;

    int option;
    int value;
    cin >> value; //initialisation assuming atleast one value is input

    dir *d;
    d = new (dir);
    d->data = value;
    d->next = nullptr;
    d->subdir = nullptr;

    dir *answer;

    while (true)
    {

        if (!d)
            break;
        cin >> option;
        cin >> value;

        //types of input 0 -1 val | 0 -1 -1 val | -1 val | 0 -1 -1 -1 val |
        if (option == 0)
        {
            while (value == -1)
            {
                answer = input(-1, -2, d);
                if (!answer)
                {
                    if (d)
                    {
                        print_dirs_length_first(d);
                        print_dirs_depth_first(d);
                    }
                    d = answer;
                    break;
                }
                d = answer;
                cin >> value;
            }
            if (!d)
                break;
            d = input(option, value, d);
        }

        else
            d = input(option, value, d);
    }
}