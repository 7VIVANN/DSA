#include <iostream>
#include <string>

using namespace std;
struct student;
struct course;
typedef struct node
{
    int rollno;
    struct node *next_student; //next record where rollno is mentioned
    char course_name;
    struct node *next_course; //next record where course_name is mentioned
    struct node *next_record;
} registration;
typedef struct student
{
    int rollno;
    registration *next_student;
} student;
typedef struct course
{
    char course;
    registration *next_course;
} course;

void init(student *student_array, course *course_array)
{
    int number_of_students = 5;
    int number_of_courses = 4;

    for (int i = 0; i < number_of_students; i++)
    {
        student_array[i].rollno = i + 1;
        student_array[i].next_student = nullptr;
    }
    for (int i = 0; i < number_of_courses; i++)
    {
        course_array[i].course = (char)(65 + i);
        course_array[i].next_course = nullptr;
    }
}
void enroll(student &student_object, course &course_object, registration *record)
{
    int rollno = student_object.rollno;
    char course_name = course_object.course;
    bool course_found = false, student_found = false;

    registration *temp = new registration, *previous_course = course_object.next_course, *previous_student = student_object.next_student;
    temp->rollno = rollno;
    temp->course_name = course_name;
    temp->next_record = nullptr;
    temp->next_course = nullptr;
    temp->next_student = nullptr;

    while (record)
    {
        if (record->next_record)
            record = record->next_record;
        else
            break; //early exit statement
    }
    if (previous_student)
    {
        while (previous_student->next_student)
            previous_student = previous_student->next_student;
        previous_student->next_student = temp;
    }
    else
        student_object.next_student = temp;

    if (previous_course)
    {
        while (previous_course->next_course)
            previous_course = previous_course->next_course;
        previous_course->next_course = temp;
    }
    else
        course_object.next_course = temp;

    record->next_record = temp;
}
string query(student student_object)
{
    string s = "";
    registration *record = student_object.next_student;
    while (record)
    {
        s += record->course_name;
        record = record->next_student;
    }
    return s;
}
string query(course course_object)
{
    string s = "";
    registration *record = course_object.next_course;
    while (record)
    {
        s += to_string(record->rollno);
        record = record->next_course;
    }
    return s;
}
void print_all_registrations(registration *record)
{
    while (record)
    {
        cout << record->rollno << " " << record->course_name << " ";
        record = record->next_record;
    }
}
int find_student(student *student_array, int rolno)
{
    int number_of_students = 5;
    for (int i = 0; i < number_of_students; i++)
    {
        if (student_array[i].rollno == rolno)
            return i;
    }
    return 0;
}

int main()
{
    student student_array[5]; //for dynamic number of student instaed of an array use a vector
    course course_array[4];
    registration *record = new registration; //dummy head
    record->course_name = '!';
    record->rollno = -1;
    record->next_record = nullptr;

    init(student_array, course_array);

    int rollno;
    char course_name;
    while (true)
    {
        cin >> rollno;
        cin >> course_name;
        if (rollno == -1)
            break;

        enroll(student_array[find_student(student_array, rollno)], course_array[(int)course_name - 65], record); //peoper params are necessary
    }
    record = record->next_record; //removing the dummy head

    // 1 -> std roll number
    // 2 -> course name
    // 3 -> course-name-1 course-name-2 common students enrolled
    // 4 -> std-no-1 std-no-2 common courses taken
    string result = "",result2="";

    cin >> rollno;
    result = query(student_array[find_student(student_array, rollno)]);
    for(int i=0;i<result.length();i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";

    cin >> course_name;
    result = query(course_array[(int)course_name - 65]);
    for(int i=0;i<result.length();i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";

    cin >> course_name;
    result = query(course_array[(int)course_name - 65]);
    cin >> course_name;
    result2 = query(course_array[(int)course_name - 65]);
    for (int i = 0; i < result.length(); i++)
    {
        int x = stoi(result.substr(i, 1));
        if (x == -1)
            break;
        for (int j = 0; j < result2.length(); j++)
        {
            int y = stoi(result2.substr(j, 1));
            if (y == -1)
                break;
            if (x == y)
                cout << x << " ";
        }
    }
    cout << "\n";

    cin >> rollno;
    result = query(student_array[find_student(student_array, rollno)]);
    cin >> rollno;
    result2 = query(student_array[find_student(student_array, rollno)]);
    for (int i = 0; i < result.length(); i++)
    {

        char x = (result[i]);
        if (x == -1)
            break;
        for (int j = 0; j < result2.length(); j++)
        {
            char y = (result2[j]);
            if (y == -1)
                break;
            if (x == y)
                cout << x << " ";
        }
    }
    cout << "\n";

    print_all_registrations(record);
}