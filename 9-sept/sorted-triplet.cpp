#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=7;
    int ar[7]={5,4,3,7,6,1,9};
    int pos[3];
    int counter;
    for (int i = 0; i < n; i++)
    {
        pos[0] = i;
        counter = 0;
        for (int j = i+1; j < n; j++)
        {
            if(ar[j]>ar[pos[counter]])
                pos[++counter] = j;
            if (counter == 2)
            {
                cout << ar[pos[0]] << " " << ar[pos[1]] << " " << ar[pos[2]] << endl;
                break;
            }
        }
        if(counter==2)
            break;
    }
    

}