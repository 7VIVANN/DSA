#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int lp = n - 1;
    int fp = 0;
    cout << "ENTER THE DATA IN THE FOLLOWING FORMAT :( f or l ) (value) \n";
    cout << "ff is to enter the data from the beginning  and l is to enter the data from last\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        char c;
        cin >> c >> x;
        if(c=='f'){
            arr[fp] = x;
            fp++;
        }
        else
        {
            arr[lp] = x;
            lp--;
        }
        if(fp-1>lp){
            cerr << "THE AMOUNT OF FIRST ELEMENTS HAVE EXCEEDED THE LAST ONES ";
            exit(2);
        }
        
    }
    cout << "\n";
    for (auto &&i : arr)
    {
        cout << i<<"\t";
    }
    
    
}