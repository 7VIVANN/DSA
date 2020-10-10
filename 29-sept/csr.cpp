#include <iostream>
using namespace std;
struct r;
typedef struct s
{
    int rollno;
    struct r *rptr;
} student;
typedef struct c
{
    char course;
    struct r *rptr;
}course;
typedef struct r
{
    int student_tag;
    union 
    {
        struct r *s_rptr;
        struct s *sptr;
    };
    int course_tag;
    union
    {
        struct r *c_rptr;
        struct c *cptr;
    };

} registration;
void append(student *s,course *c){
    registration *temp = new registration;
    temp->student_tag = 1;
    temp->sptr = s;
    if(s->rptr){
        registration *r=s->rptr;
        while (r->student_tag==0)
        {
            r = r->s_rptr;
        }
        r->student_tag = 0;
        r->s_rptr = temp;
    }
    else
    {
        s->rptr = temp;
    }
    if (c->rptr)
    {
        registration *r = c->rptr;
        while (r->course_tag == 0)
        {
            r = r->c_rptr;
        }
        r->course_tag = 0;
        r->c_rptr = temp; //this means students roll nos are entered in order
    }
    else
    {
        c->rptr = temp;
    }
    
    temp->course_tag = 1;
    temp->cptr = c;
}
void initialise(student **st,course **co){
    

    int no_of_students = 5;
    int no_of_courses = 4;

    for (int i = 0; i < no_of_courses; i++)
    {
        co[i] = new course;
        co[i]->course = char(65+i);
        co[i]->rptr = nullptr;
    }
    
    for (int i = 0; i < no_of_students; i++)
    {
        st[i] =new student;
        cin >> st[i]->rollno;
        st[i]->rptr = nullptr;
        char x='!';
        while (true)
        {
            cin >> x;
            if(x=='#')
                break;
            int char_index = (int)x - 65;
            append(st[i],co[char_index]);
        }
    }

}
void course_query(student **st,course **co,char course_name){
    int course_index = int(course_name) - 65;
    registration *r = new registration;
    r = co[course_index]->rptr;
    while (r->course_tag==0)
    {
        cout << r->sptr->rollno << " ";
        r = r->sptr->rptr;
    }
}
int main(){
    student *st[5];
    course *co[4];

    initialise(st,co);
    char x;
    cin >> x;
    course_query(st, co, x);
}