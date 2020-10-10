#include <iostream>
using namespace std;
union u
{
    int a;
    char b;
};
int main(){
    int n;
    cin >> n;
    union u arr[n];
    int tag[n];
    int fp, lp;
    fp = 0;
    lp = n - 1;
    cout << "ENTER THE DATA IN THE FOLLOWING FORMAT :( 1 or 2 ) (value) \n";
    cout << "1 is for int data-type and 2 is character-type \n";
    for (int i = 0; i < n; i++)
    {
        cout << "TAG :";
        int x;
        cin >> x;
        tag[i] = x;
        cout << "value :";
        if(x==1)
           {
               cin >> arr[fp].a;
               fp++;
           }
        else
           {
               cin >>arr[lp].b;
               lp--;
           }
        if (fp-1 > lp)
           {
               cerr << "THE AMOUNT OF FIRST INTEGERS HAVE EXCEEDED THE CHARACTERS . ";
               exit(1);
           }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if(tag[i]==1){
            cout << arr[i].a<<"\t";
        }
        else
        {
            cout << arr[i].b<<"\t";
        }
        
    }  
}