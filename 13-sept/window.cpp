#include <iostream>
using namespace std;

int main(){
    int a;
    int max;
    cin >> a;
    int A[a];
    for (int i = 0; i < a; i++)
    {
        cin >> A[i];
        if(i==0)
            max = A[i];
        max = max > A[i] ? max : A[i];

    }
    int B;
    cin >> B;
    if (B > a)
    {
        cout << max;
    }
    else
    {
        int C[a - B];
        int i;
        for ( i = 0; i < a; i++)
        {
            int x = i + B;
            if (x > a)
                break;
            max = A[i];
            for (int j = i; j < x; j++)
            {
                max = max > A[j] ? max : A[j];
            }
            C[i] = max;
        }
        for (int k = 0; k < i; k++)
        {
            cout << C[k]<<" ";
        }
        
    }
}