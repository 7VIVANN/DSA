#include <iostream>
using namespace std;
void format(int *a,int count){
    for (int i = 0; i < count; i++)
    {
        if (a[i]%2!=0)
        {
            for (int j = i+1; j < count; j++)
            {
               if (a[j]%2==0)
               {
                   int t = a[i];
                   a[i] = a[j];
                   a[j] = t;
                   break;
               }
               
            }
        }
        
    }
  
}
int find(int *a,int count){
    for (int i = 0; i < count; i++)
    {
        if(a[i]%2 != 0){
            return i;
        }
    }
    
}
void sort(int *a, int start, int end){
    for (int i = start; i < end; i++)
    {
        int s = i;
        for (int j = i+1; j < end; j++)
        {
            if(a[s]>a[j])
                s = j;
        }
        if(s!=i){
        int t = a[s];
        a[s] = a[i];
        a[i] = t;
        }
    }
    
} 
int main(int argc, char *argv[])
{

    int a[argc - 1];
    for (int i = 1; i < argc; ++i)
        a[i - 1] = atoi(argv[i]);

    format(a,argc-1);
    int k = find(a, argc - 1);
    sort(a, 0, k);
    sort(a, k, argc - 1);
    for (int i = 0; i < argc-1; i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}