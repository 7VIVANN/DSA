#include <iostream>
#include <string>
using namespace std;
string DATE[7], MONTH[12], DIVIDER[12];
int day, month, year;
void input(){
    cin >> day >> month >> year;
    month = month < 2 ? month + 10 : month - 2;
}
void init(){
    //months according to zeller's rule
    DATE = { 'SUN' ,'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT'};
    MONTH = {
        'MARCH',
        'APRIL',
        'MAY',
        'JUNE',
        'JULY',
        'AUGUST',
        'SEPTEMBER',
        'OCTOBER',
        'NOVEMBER',
        'DECEMBER',
        'JANUARY',
        'FEBRUARY'
    };
    DIVIDER = {1,0,1,0,1,1,0,1,0,1,1,-1};
}
int isLeap(int year){
    return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) ? 1 : 0;
}
int zeller(int k,int m,int y){
    //ZELLER'S RULE f=k+[(13*m-1)/5]+D+[D/4]+[C/4]-2*C
    int D = y % 100;
    int C = y - D;
    int f = k + int((13 * m - 1) / 5) + D + int((D / 4)) + int((C / 4)) - 2 * C;
    return f % 7;
}
void break_the_month(int *day_of_the_week, int *index_of_the_month ,int *day_of_the_month,int *divider){
    cout << MONTH[*index_of_the_month];
    cout << "SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT";
    for (int j = 0; j < *day_of_the_week; j++)
    {
        cout << "\t\t";
    }
    *day_of_the_month = 1;
    cout << *day_of_the_month;
    *index_of_the_month = *index_of_the_month > 11 ? *index_of_the_month - 10 : *index_of_the_month++;
    *divider = DIVIDER[*index_of_the_month];
}
void horizontal(){
    cout << year;
    cout << month<<"\n";
    cout << "SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT";
    int day_of_the_week, day_of_the_month ,index_of_the_month, divider;
    day_of_the_month = 1;
    index_of_the_month = month - 1;
    divider = DIVIDER[index_of_the_month];

    for (int i = 1; i <= 366; i++)
    {
        day_of_the_week = i % 7;
        day_of_the_month++;

        if ((day_of_the_month == divider + 30) || ((isLeap == 1) && (index_of_the_month == 11) && (day_of_the_month == 29))){
            break_the_month(&day_of_the_week,&index_of_the_month,&day_of_the_month,&divider);
            continue;
        }
        cout << day_of_the_month << "\t";
    }
    
}
int main(){
    
    
    
}