#include <iostream>
using namespace std;
//1
struct s{
    int a;
    char b;
    float c;
};

//2
struct s2{
    int d;
    float e;
};

//3
struct s3
{
    int a;
    struct s2 *b;
    char c;
};

//4
struct s4{
    int c;
    char d;
};
struct s5{
    int a;
    struct s4 *b;
}

//5 - LINKED LIST
struct s6{
    int a;
    struct s6 *b;
}

//6 - BINARY TREE a: LEFT-CHILD b:RIGHT-CHILD
struct s7{
    struct s7 *a;
    int b;
    struct s7 *b;
};

//7
struct s8{
    struct s8 *e;
    int f;
    struct s8 *g;
};
struct s9{
    struct s9 *a;
    int b;
    struct s9 *c;
    char d;
};

//8
union U{
    int a;
    char b;
};

int main(){
    //1
    struct s o1;
    //2
    struct s *p2;
    p2 = new (struct s);
    p2->a = 5; //a,b,c, are field variables not actual variables thus only a single variable defined p2 
    //3
    struct s3 *p3;
    p3 = new (struct s3);//p3 will point to the new struct created just new keyword
    p3->b = new (struct s2);
    p3->b->d = 10;
    //4
    struct s4 *b;
    struct s5 o5;
    o5.b = new (struct s4);
    //6
    struct s8 *D;

    //8
    union U A[6];
    int tag[6];
    
    //9
    struct S2{
        struct S2 *d;
        struct S2 *e;
    }
    struct S4
    {
        struct S4 *h;
        int i;
        struct S4 *j;
    };
    struct S3{
        
    };

    cout << "INPUT THE TAG(1:int , 2:character) THEN the element";
    for (int i = 0; i < 6; i++)//input
    {
        cin >> tag[i];
        if(tag[i]==1)
            cin >> A[i].a;
        else if(tag[i]==2)
            cin >> A[i].b;
    }
    for (int i = 0; i < 6; i++)//ouput
    {
        if (tag[i] == 1)
           cout<< A[i].a;
        else if (tag[i] == 2)
           cout<< A[i].b;
    }
    
    //9

}