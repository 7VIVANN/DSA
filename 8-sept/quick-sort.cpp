#include <iostream>
using namespace std;
void show(int *ar,int &n){
    for (int i = 0; i < n; i++)
    {
        cout << ar[i]<<" ";
    }
    cout << endl;
}
void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}
int partition_lower_pivot(int *ar,int low,int high){
    int l = low;
    int pivot = low;
    int i = low + 1;
    if(low<high){
        while (i <= high)
        {
            if (ar[pivot] > ar[i])
            {
                l++;
                swap(ar[l], ar[i]);
            }
            i++;
        }
        swap(ar[l], ar[pivot]);
        return l;
    }
    else
    {
        return -1;
    }
}
int partition_higher_pivot(int *ar, int low, int high)
{ 
    int h = high;
    int pivot = high;
    int i = high-1;
    if (high>low)
    {
        while (i>=0)
        {
            if (ar[pivot] < ar[i])
            {
                h--;
                swap(ar[h], ar[i]);
            }
            i--;
        }
        swap(ar[h], ar[pivot]);
        return h;
    }
    else
    {
        return -1;
    }   
}
void quick(int *ar, int low, int high)
{
    int p = partition_higher_pivot(ar, low, high);
    if(p<0)
        return;
    quick(ar,low, p - 1);
    quick(ar,p + 1, high);
}
void dual_quick(int *ar,int low,int high){
    int l = partition_lower_pivot(ar, low,high);
    if (l < 0)
        return;
    dual_quick(ar, low, l - 1);//LEFT OF PARTITION

    int r = partition_higher_pivot(ar,l-1, high);
    if (r < 0)
        return;
    dual_quick(ar, r + 1, high);//RIGHT OF PARTITION

    dual_quick(ar, l+1, r-1);//INSIDE THE PARTITION
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    dual_quick(ar, 0, n - 1);
    show(ar,n);
}