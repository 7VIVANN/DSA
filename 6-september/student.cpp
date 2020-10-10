#include <iostream>
using namespace std;
union u
{
    char cno[10];
    int hno;
};
struct student
{
    int rno;
    int tag;
    union u no;
};
int main(){
    struct student *s[5];
    for (int i = 0; i < 5; i++)
    {
        s[i] = new (struct student);
        cin >> s[i]->rno >> s[i]->tag;
        if(s[i]->tag==1){
            cin >> s[i]->no.cno;
        }
        else
        {
            cin >> s[i]->no.hno;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << s[i]->rno << "\t";
        if (s[i]->tag == 1)
        {
            cout<< s[i]->no.cno;
        }
        else
        {
            cout<< s[i]->no.hno;
        }
        cout << endl;
    }
}