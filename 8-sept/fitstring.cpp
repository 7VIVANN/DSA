#include <string>
#include <iostream>
using namespace std;

void add(int f0, int f1, int &i, int &x,int *ar);
void subtract(int f0, int f1, int &i, int &x,int *ar);

void add(int f0, int f1, int &i, int &x,int *ar)
{
    int fib = f0 + f1;
    i++;
    if(x==fib){
        if(ar[i]==0){
            ar[i] = 1;
            return;
        }
        else{
            ar[i] = 0;
            x += fib;
        }
    }
    else if(x<fib)
    {
        if (ar[i] == 0) {
            ar[i] = 1;
            x -= fib;
            x = -x;
            i = 0;
            subtract(0, 1, i, x,arr);
            return ;
        }
    }
    add(f1, fib, i, x,ar);
}
void subtract(int f0, int f1, int &i, int &x,int *ar)
{
    int fib = f0 + f1;
    i++;
    if (x == fib)
    {
        if (ar[i] == 1)
        {
            ar[i] = 0;
            return;
        }
        else
        {
            ar[i] = 1;
            x += fib;
        }
        
    }
    else if (x < fib)
    {
        if (ar[i] == 1)
        {
            ar[i] = 0;
            x -= fib;
            x = -x;
            i = 0;
            add(0, 1, i, x,arr);
            return;
        }
    }

    subtract(f1, fib, i, x);
}
int main(){
    int ar[20];
    int i=0;
    int x;
    string s;
    cin >> s;
    int n = s.length();
    for (int j = 0; j < 20; j++)
    {
        ar[j] = 0;
    }
    for (int j = n-1,k=0; j>=0; j--,k++)
    {
        ar[k] = stoi(s.substr(j,1));
    }
    cin >> x;
    //o for subtraction and 1 for addition
    int choice;
    cin >> choice;
    if(choice==0){
        subtract(0, 1, i, x, ar);
    }
    else
    {
        add(0, 1, i, x, ar);
    }
    
    for (int k = 20; k >= 0; k--)
    {
        if(ar[k]==1){
            for (int j = k; j >=0; j--)
            {
                cout << ar[j];
            }
            break;
        }
    }
    
}