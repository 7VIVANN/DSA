#include <iostream>
using namespace std;
void sort(int *a, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        int s = i;
        for (int j = i + 1; j < end; j++)
        {
            if (a[s] > a[j])
                s = j;
        }
        if (s != i)
        {
            int t = a[s];
            a[s] = a[i];
            a[i] = t;
        }
    }
}
int main(int argc, char **argv)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    int k = 3;
    sort(a, 0, k);
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = k; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a, k, 10);
    for (int i = 0; i < argc; i++)
    {
        cout << a[i] << " ";
    }
}