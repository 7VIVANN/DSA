#include <iostream>
using namespace std;
int m = 10;
int n = 10;
int ar[10][10] = {
  // 0 1  2  3 4  5 6  7 8  9
    {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},//0
    {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},//1
    {1, 1, 1, 1, 0, 0, 1, 0, 0, 0},//2
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},//3
    {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},//4
    {0, 1, 0, 1, 0, 0, 1, 1, 1, 1},//5
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},//6
    {0, 0, 0, 1, 0, 0, 1, 1, 1, 0},//7
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 0},//8
    {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}//9
};
int discovered[10][10];
int err[] = {-1, -1};
struct queue
{
    int front;
    int rear;
    int size;
    int elements[20][2];
};
void enque(struct queue &q, int *x)
{
    int a = x[0];
    int b = x[1];
    if (q.rear + 1 % q.size == q.front)
        cout << "overflow";
    else if (q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = (q.rear + 1) % q.size;
        q.elements[q.rear][0] = a;
        q.elements[q.rear][1] = b;
    }
    else
    {
        q.rear = (q.rear + 1) % q.size;
        q.elements[q.rear][0] = a;
        q.elements[q.rear][1] = b;
    }
}
int *deque(struct queue &q)
{
    if (q.front == -1)
        return err;
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
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
bool is_out_of_range(int x, int y)
{
    return ((x < 0 || x > m - 1 || y < 0 || y > n - 1) ? true : false);
}
void search(struct queue &q, int look, int &number)
{
   
    int *t = deque(q);
    int x = t[0];
    int y = t[1];
   
    //here for valid and matching look i assign loook*assign
    //this is beacuse when look=0 no number is assigned to water
    //or else assign something like 1*number of the island

    if (ar[x + 1][y] ==1)
    {
        int a[] = {x, y};
        a[0]++;
        if (!is_out_of_range(a[0], a[1]) && discovered[a[0]][a[1]]==0)
        {
            discovered[a[0]][a[1]]=1;
            enque(q, a);
            ar[x + 1][y] = number * look;
        }
        
        
    }
    if (ar[x][y + 1] ==1)
    {
        int a[] = {x, y};
        a[1]++;
        if (!is_out_of_range(a[0], a[1]) && discovered[a[0]][a[1]]==0)
        {
            discovered[a[0]][a[1]]=1;
            enque(q, a);
            ar[x][y + 1] = number * look;
        }
        
        
    }

    if (ar[x - 1][y] ==1)
    {
        int a[] = {x, y};
        a[0]--;
        if (!is_out_of_range(a[0], a[1]) && discovered[a[0]][a[1]]==0)
        {
            discovered[a[0]][a[1]]=1;
            enque(q, a);
            ar[x - 1][y] = number * look;
        }
    }
    if (ar[x][y - 1] ==1)
    {
        int a[] = {x, y};
        a[1]--;
        if (!is_out_of_range(a[0], a[1]) && discovered[a[0]][a[1]]==0)
        {
            discovered[a[0]][a[1]]=1;
            enque(q, a);
            ar[x][y - 1] = number * look;
        }
    }
    if (ar[x + 1][y + 1] ==1)
    {
        int a[] = {x, y};
        a[0]++;
        a[1]++;
        if (!is_out_of_range(a[0], a[1])&& discovered[a[0]][a[1]]==0)
        {
            enque(q, a);
            discovered[a[0]][a[1]]=1;
            ar[x + 1][y + 1] = number * look;
        }
        
        
    }
    if (ar[x - 1][y - 1] ==1)
    {
        int a[] = {x, y};
        a[0]--;
        a[1]--;
        if (!is_out_of_range(a[0], a[1])&& discovered[a[0]][a[1]]==0)
        {
            enque(q, a);
            discovered[a[0]][a[1]]=1;
            ar[x - 1][y + 1] = number * look;
        }
        
        
    }
    if (ar[x + 1][y - 1] ==1)
    {
        int a[] = {x, y};
        a[0]++;
        a[1]--;
        if (!is_out_of_range(a[0], a[1])&& discovered[a[0]][a[1]]==0)
        {
            enque(q, a);
            discovered[a[0]][a[1]]=1;
            ar[x + 1][y + 1] = number * look;
        }
    }
    if (ar[x + 1][y + 1] ==1)
    {
        int a[] = {x, y};
        a[0]++;
        a[1]--;
        if (!is_out_of_range(a[0], a[1])&& discovered[a[0]][a[1]]==0)
        {
            enque(q, a);
            discovered[a[0]][a[1]]=1;
            ar[x - 1][y + 1] = number * look;
        }
    }

    t = deque(q);
    if (t[0] == -1)
    {
        //you cant search what you are looking for anymore
        //look for the opppsite of it
        //when first time this occurs you wont search anymoore land
        //start looking for water
            number += look;
            look = look ^ 1;
            int previous[] = {x, y};
            enque(q, previous);
    }
    else
    {
        enque(q, t);
    }
    search(q, look, number);
}
int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 10;
    int number = 2;
    for (auto &&i : discovered)
    {
        for (auto &&j : i)
        {
            j = 0;
        }
        
    }
    
    int start[] = {0, 0};
    enque(q, start);
    discovered[0][0] = 1;
    search(q, 1, number);
    cout << number-1;
}
