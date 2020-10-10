#include <iostream>
using namespace std;
struct s2
{
    struct s2 *d;
    struct s2 *e;
};
struct s4{
    struct s4 *h;
    int i;
    struct s4 *j;
};
struct s3{
    struct s4 *f;
    char g;
};
struct s1
{
    struct s1 *a;
    struct s2 *b;
    struct s1 *c;
};

int main(){
    struct s3 *s;
    s = new (struct s3);
    cout << sizeof(s);
    s->f->i=10;
    cout << s->f->i;
    cout << endl;
}