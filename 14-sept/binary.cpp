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
            ;
            q.front = (q.front + 1) % q.size;
        }

        return t;
    }
}
void binary()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 16;
    int n=8;
    int sum = 0;
    int carry = 0;
    enque(q, 0);
    int bits = 1;
    for (int i = 0; i < n; i++)
    {
        sum = 1;
        carry = 0;
        int number_of_bits_processed = 0;
        do
        {
            number_of_bits_processed++;

            int nthbit = deque(q);
            nthbit += carry;
            sum += nthbit;

            if (sum > 1)
            {
                carry = 1;
                sum = 0;
            }
            else
            {
                carry = 0;
            }
            cout << sum;
            enque(q, sum);

        } while (carry != 0 && number_of_bits_processed < bits);

        while(number_of_bits_processed<bits){
            int s = deque(q);
            cout << s;
            enque(q, s);
            number_of_bits_processed++;
        }
        if(carry>0){
            bits++;
            cout << carry;
            enque(q, carry);
        }
        cout << endl;
    }
}