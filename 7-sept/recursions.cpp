#include <iostream>
using namespace std;
void convert(int n,int b){
    if(n<b)
    {
        if(n<10)
        {   
            cout<<char(48+(n % b));//49 is 1 in ascii
        }

        else
        {
            cout<<char( 65 + n - 10);
            
        };
    }
    else{
         
        convert(n / b, b);
        cout << char(48 + (n % b));
    }
}
int main(){
    int n;
    cin >> n;
    convert(100, n);

    
}