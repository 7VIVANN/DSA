#include <iostream>
using namespace std;
void call(){
    if(1==1){
        cout << "terminate here";
        return;
    }
    cout << "not here";
    return;
}
int main(){
    int r = 10;
    call();
}