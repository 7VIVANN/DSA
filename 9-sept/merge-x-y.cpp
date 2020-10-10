#include <bits/stdc++.h>
using namespace std;
int main(){
    int a = 9;
    int b = 5;
    int x[9] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
    int y[5] = {1, 8, 9, 10, 15};
    //focus variables
    int m = 0;
    int n = 0;
    
    for (int i = 0; i < a; i++)
    {
        if(x[i]==0){
            if (m<a&&x[m] == 0)
            {
                m++;
                i--;
                continue;
            }

            if(m<a&&x[m]<y[n]){
                x[i] = x[m];
                x[m] = 0;
                m++;
            }
            
            else
            {
                x[i] = y[n];
                n++;
            }
            
        }
        else
        {
            if (m<a && x[m] < y[n])
            {
                x[i] = x[m];
                m++;
            }
            else
            {
                swap(x[i], y[n]);
            }
        }
        
        
        
    }
    for (int i = 0; i < a; i++)
    {
        cout << x[i] << " ";
    }
}