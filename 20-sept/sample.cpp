#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<vector<int>> sq(2);
    vector<int> v = {1, 2, 3};
    for (int i = 0; i < 2; i++)
    {
        /* code */
    }
    
    
    for (auto &&i : sq)
    {
        for (auto &&j : v)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
}