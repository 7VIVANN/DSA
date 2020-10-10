#include <iostream>
using namespace std;
int k;
int n;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int partition(int *ar, int low, int high)
{
    int pi = low;
    if (low < high)
    {
        for (int i = low + 1; i < high; i++)
        {
            if (ar[pi] > ar[i])
            {
                low++;
                swap(ar[i], ar[low]);
            }
        }
        swap(ar[pi], ar[low]);
        pi = low;
    }
    return pi;
}
void quicksort(int *ar, int low, int high)
{
    int pi = partition(ar, low, high);
    if (pi == k-1)
    {
        cout << ar[pi]<<" "; //ascending order so return kth smallest
        return;
    }
    // cout << pi << " " << low << " " << high<<" \n ";

    if (low < pi - 1)
        quicksort(ar, low, pi - 1);
    if (pi + 1 < high)
        quicksort(ar, pi + 1, high);

}
int main()
{
    n = 9;
    int ar[n] = {3,5,4,6,1,2,8,7,10};// 1 2 3 5 6 7 8 9 10
    for (int  i = 1; i < n+1; i++)
    {
        k = i;
        quicksort(ar, 0, n);
    }
    
    // cin >> k;
    // quicksort(ar, 0, n);
}