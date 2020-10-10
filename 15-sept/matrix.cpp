#include <iostream>
using namespace std;
//iam assuming that the values which are not accessible(the black blocks) as 0
int m = 4, n = 5;
int ar[4][5] = {
    {-1,-9,0,-1,0},
    {-8,-3,-2,9,-7},
    {2,0,0,-6,0},
    {0,-7,-3,5,-4},
};
int discovered[4][5];

struct queue
{
    int front;
    int rear;
    int size;
    int elements[20][3];
};
void enque(struct queue &q, int *x)
{
    int a = x[0];
    int b = x[1];
    int tag = x[2];
    if (q.rear + 1 % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = (q.rear + 1) % q.size;
        ;
        q.elements[q.rear][0] = a;
        q.elements[q.rear][1] = b;
        q.elements[q.rear][2] = tag;
    }
    else
    {
        q.rear = (q.rear + 1) % q.size;
        ;
        q.elements[q.rear][0] = a;
        q.elements[q.rear][1] = b;
        q.elements[q.rear][2] = tag;
    }
}
int* deque(struct queue &q)
{
    if (q.front == -1)
        return nullptr;
    else
    {
        int *t;
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
bool out_of_bounds(int x,int y){
    if(x<0||x>m-1||y<0||y>n-1)
        return true;
    else
    {
        return false;
    }
    
}
void correct(int x, int y, int tag,struct queue &q)
{
    ;
    if (discovered[x-1][y]==0 && ar[x-1][y] < 0)
    {
        discovered[x-1][y] = tag+1;
        
        ar[x - 1][y] = -ar[x - 1][y];
        int temp[] = {x - 1, y,tag++};
        enque(q, temp);
    }
    if (discovered[x][y-1]==0 && ar[x][y-1] < 0)
    {
        discovered[x][y-1] = tag+1;
       
        ar[x][y-1] = -ar[x][y-1];
        int temp[] = {x, y-1,tag++};
        enque(q, temp);
    }
    if (discovered[x+1][y]==0 && ar[x + 1][y] < 0)
    {
        discovered[x+1][y] = tag+1;
        
        ar[x + 1][y] = -ar[x + 1][y];
        int temp[] = {x + 1,y,tag++};
        enque(q, temp);
    }
    if (discovered[x][y+1]==0 && ar[x][y+1] < 0)
    {
        discovered[x][y+1] = tag+1;
        
        ar[x][y+1] = -ar[x][y+1];
        int temp[] = {x, y+1,tag++};
        enque(q, temp);
    }
    
}
void find(struct queue &q)
{
    int *next;
    next= deque(q);
    if (next == nullptr)
        return;
    int x = next[0];
    int y = next[1];
    int tag = next[2];
    if(out_of_bounds(x,y))
        return;
    correct(x, y,tag, q);
    find(q);
}
int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 15;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            discovered[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(ar[i][j]>0)
            {
                int temp[] = {i, j,0};
                discovered[i][j] = 1;
                enque(q, temp);
            }
        }
        
    }

    find(q);
    int max = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            max = max > discovered[i][j] ? max : discovered[i][j];
        }
    }
    cout << max-1;
}