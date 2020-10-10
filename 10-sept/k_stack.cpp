#include <iostream>
#include <string>
using namespace std;
int size_of_each;
struct k_stack
{
    int size;
    int index; //DIAGRAM
};

void k_stack_push(struct k_stack &s, int x,int *ar)
{
    s.size++;
    if (s.size >size_of_each)
        cout << "k_stack overflow" << endl;
    else
        ar[s.index++]=x;
}
int k_stack_pop(struct k_stack &s,int *ar)
{
    s.size--;
    if(s.size==-1)
    {
        cout << "k_stack underflow\n";
        return 0;
    }
        
    return ar[--s.index];
}

int main(){
    int n = 10;
    int ar[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 5;
    size_of_each = n / k;
    struct k_stack st[k];
    for (int i = 0; i < n; i+=size_of_each)
    {
        st[i / 2].size = 0;
        st[i / 2].index = i;
    }
    int result=0;
    cout << "(k_stack number) (value) (options:1 k_stack_push -1 k_stack_pop value for k_stack_pop 0)\n ";
    while (result!=-1)
    {
        int a, b,c;
        cin >> a >> b >> c;
        switch (c)
        {
        case 1:
            k_stack_push(st[a-1], b, ar);
            result = 1;
            break;
        case -1:
            result = k_stack_pop(st[a-1], ar);
            if (result!=0)
            {
                cout << result<<endl;
            }
                
            break;
        default:
            cout << "wrong option"<<endl;
        }
    }
    cout << "exit with status " << result;
}