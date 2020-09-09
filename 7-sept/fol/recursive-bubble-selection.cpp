#include <iostream>
using namespace std;
void bubble(int &i, int &j, int *ar, int n)
{
    if (j == n - 1)
    {
        j = i;
        i += 1;
    }
    else if(j<n-1)
    {

        if (ar[j] > ar[j + 1])
        {
            int t = ar[j];
            ar[j] = ar[j + 1];
            ar[j + 1] = t;
        }
        j += 1;
    }
    if(i<n)
    bubble(i, j, ar, n);
}

void select(int sm, int &i, int &j, int *ar, int &n)
{
    if (j == n - 1)
    {
        int t = ar[sm];
        ar[sm] = ar[i];
        ar[i] = t;

        i += 1;
        sm = i;
        j = i + 1;
    }
    else 
    {
        sm = ar[sm] < ar[j] ? sm : j;
        j += 1;
    }
    if (i < n &&  (j <= n - 1))
        select(sm, i, j, ar, n);
}
int main()
{
    int n = 6;
    int ar[6];
    int br[6];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> br[i];
    }
    int i = 0;
    int j = 0;
    bubble(i, j, ar, n);
    i = 0;
    j = 0;
    bubble(i, j, br, n);
    for (auto &&k : ar)
    {
        cout << k;
    }
    for (auto &&k : br)
    {
        cout << k;
    }
    // int ar[4] = {1, 2, 5,3};
    // int i = 0;
    // int j = 1;
    // int n = 4;
    // select(0,i, j, ar,n);
    // for (auto &&i : ar)
    // {
    //     cout << i;
    // }


}