#include <iostream>
using namespace std;
int m = 8, n = 8;
int ar[8][8];
int destx, desty;
int err[] = {-1, -1};
struct queue
{
    int front;
    int rear;
    int size;
    int elements[25][2];
};
void enque(struct queue &q, int *x)
{
    if (q.rear + 1 % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
        q.elements[q.rear][0] = x[0];
        q.elements[q.rear][1] = x[1];
        q.rear = (q.rear + 1) % q.size;
    }
    else
    {
        q.elements[q.rear][0] = x[0];
        q.elements[q.rear][1] = x[1];
        q.rear = (q.rear + 1) % q.size;
    }
}
int* deque(struct queue &q)
{
    if (q.front == -1)
        return err;
    else
    {
        int* t;
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

bool is_out_of_bounds(int x, int y)
{
    if (x < 0 || y < 0 || x > m - 1 || y > m - 1)
        return true;
    else
    {
      return  false;
    }
}
void find(struct queue &q,int tag) {
    int *t = deque(q);
    int x = t[0];
    int y = t[1];
    if(x==-1 && y==-1)
        return;
    if(x==destx && y==desty)
    {
        cout << tag;
        return;
    }

    if(is_out_of_bounds(x,y))
    {   
            find(q, tag);
       
        return;                                        
                                                         
    }                                                  
                                                        

    if(ar[x - 2][y+1]==0){
        ar[x - 2][y + 1] = tag;
        int temp[] = {x - 2,y + 1};
        enque(q, temp);
    }
    if (ar[x + 2][y - 1] == 0)
    {
        ar[x + 2][y - 1] = tag;
        int temp[] = {x + 2,y - 1};
        enque(q, temp);
    }
    if (ar[x - 1][y -2] == 0)
    {
        ar[x - 1][y - 2] = tag;
        int temp[] = {x -1,y -2};
        enque(q, temp);
    }
    if (ar[x + 1][y + 2] == 0)
    {
        ar[x + 1][y + 2] = tag;
        int temp[] = {x + 1,y + 2};
        enque(q, temp);
    }

    if (ar[x - 1][y + 2] == 0)
    {
        ar[x - 1][y + 2] = tag;
        int temp[] = {x - 1, y + 2};
        enque(q, temp);
    }
    if (ar[x + 1][y - 2] == 0)
    {
        ar[x + 1][y - 2] = tag;
        int temp[] = {x + 1, y - 2};
        enque(q, temp);
    }
    if (ar[x - 2][y - 1] == 0)
    {
        ar[x - 2][y - 1] = tag;
        int temp[] = {x - 2, y - 1};
        enque(q, temp);
    }
    if (ar[x + 2][y + 1] == 0)
    {
        ar[x + 2][y + 1] = tag;
        int temp[] = {x + 2, y + 2};
        enque(q, temp);
    }

    find(q,tag+1);
}
int main(){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ar[i][j] = 0;
        }
        
    }
    struct queue q;
    q.size = 25;
    q.front = -1;
    q.rear = -1;

    int x, y;
    cin >> x >> y;
    cin >> destx >> desty;

    ar[x][y] = 1;
    int t[] = {x, y};
    enque(q, t);

    find(q, 1);

}