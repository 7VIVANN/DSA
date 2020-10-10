/*
u;
    even-->n->x r->y
    odd-->n->y r->x
*/
#include <iostream>
using namespace std;
struct s9
{
    struct s9* w;
    int x;
};
struct s10
{
    int y;
    struct s10* z;
};
struct s8
{
    struct s9* t;
    int u;
    struct s10* v;
};
struct s6
{
    int n;
    char o;
    struct s8* p;
};
struct s7
{
    struct s6* q;
    int r;
    struct s7* s;
};
struct s4
{
    struct s6* j;
    struct s5* k;
};
struct s5
{
    int l;
    struct s7* m;
};

struct s3
{
    struct s4* g;
    struct s3* h;
    struct s5* i;
};
struct s2
{    int e;
    struct s3* f;
};
struct s1
{
    struct s1* a;
    int b;
    struct s2* c;
    struct s1* d;
};



int main()
{
    struct s1 *S;
    S = new (struct s1);
    int a1;
    cin >> a1;
    (S->c->f->g->j->n) = a1;
    cout << a1;
    // cin >> (S->c->f->g->j->n) >> (S->c->f->i->m->r) >> (S->c->f->g->j->p->u);

    // if((S->c->f->g->j->p->u)%2==0){
    //     S->c->f->g->j->p->t->x = S->c->f->g->j->n;
    //     S->c->f->g->j->p->v->y = S->c->f->i->m->r;
    // }
    // else{
    //     S->c->f->g->j->p->t->x = S->c->f->i->m->r;
    //     S->c->f->g->j->p->v->y = S->c->f->g->j->n;
    // }
    // cout << (S->c->f->g->j->n) << (S->c->f->i->m->r) << (S->c->f->g->j->p->u) << S->c->f->g->j->p->t->x << S->c->f->g->j->p->v->y;
}