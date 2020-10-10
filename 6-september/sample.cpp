#include <iostream>
using namespace std;
struct s0
{
    int x;
    struct s00 *k;
};
struct s00
{
    int x;
    struct s000 *j;
};
struct s000
{
    int c;
};

int main(){
    struct s0 *s;
    s = new (struct s0);
    cout << sizeof(s);
    cin >> s->k->j->c;
    cout<< s->k->j->c;
    cout << endl;
}