#include <iostream>
using namespace std;
int get_n_digit(int x, int n)
{
    while (x > 1)
    {
        x--;
        n  /= 10;
    }
    return n % 10;
}
/* USE OF TAG IN THE COUNT SORT :

    >>the temptag simply copies the elements of the array into a temporary location for the tag array to accept it.
        this is beacuse the b_tag would require the tag array elements .

    >>when using count sort on the digits of elements in the array 
     the order of te digits is changed and hence it would be
      *difficult to identify which digit belonged to which element* .

    >>Thus as a work around to this i put a tag arry in the count sort so that
       whenever a digit is sorted its corresponding number is also sorted
        the b_tag is the alias for the actual array in the sort technique .

    >>In count sort while assigning each element into a new array 
        the duplicate are placed such a way that the last one always comes first because of fr[ar]--
        so if we place the elements from the rear end of the array we can maintain the order of the duplicates
    
 */
void cosort(int *ar,int *temptag,int *b,int *b_tag,int n){
    int tag[n];
    for (int i = 0; i < n; i++)
    {
        tag[i] = temptag[i];
    }
    
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        max = max > ar[i] ? max : ar[i];
    }
    max++;
    // count the frequency of ar[]
    int fr[max];
    for (int i = 0; i < max; i++)
    {
        fr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        fr[ar[i]]++;
    }
    for (int i = 1; i < max; i++)
    {
        fr[i] += fr[i - 1];
    }
    for (int i = n-1; i >=0; i--)
    {
        int pos = fr[ar[i]];
        if (pos > 0)
        {
            b[pos-1] = ar[i];
            b_tag[pos-1] = tag[i];
            fr[ar[i]] = fr[ar[i]] - 1;
            ;
        }
    }
}
int main(){
    // int n = 7;
    // int ar[n] = {82,47,3,215,540,9,63}; //82 47 3 215 540 9 63
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    
    int radix = 1;
    int digit = 1;
    do
    {
        int di[n];
        int mdi[n];

        radix = radix * 10;
    
        for (int i = 0; i < n; i++)
        {
            int D = get_n_digit(digit, ar[i]);
            di[i] = D;
        }

        cosort(di, ar, mdi, ar,n);
        digit++;

    } while (ar[n-1]>radix/10);

    for (int i = 0; i < n; i++)
    {
       cout<< ar[i]<<" ";
    }
    cout << endl;
}