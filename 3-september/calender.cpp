#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//GLOBAL VARIABLES
string DATE[7] ={"SUN","MON","TUE","WED","THU","FRI","SAT" };
string MONTH[12] = {
    "JANUARY",
    "FEBRUARY",
    "MARCH",
    "APRIL",
    "MAY",
    "JUNE",
    "JULY",
    "AUGUST",
    "SEPTEMBER",
    "OCTOBER",
    "NOVEMBER",
    "DECEMBER"};
int DIVIDER[12] = {1, -2,1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
int YEAR;
int format_months()
{
    int y = YEAR;
    if ((y % 400) == 0 || ((y % 100 != 0) && (y % 4 == 0)))
        DIVIDER[2] = -1;
}
int getcount()
{
    int k = 0;
    int m = 3;
    int y = YEAR;
    int D = y % 100;
    int C = y - D;
    int f = k + int((13 * m - 1) / 5) + D + int((D / 4)) + int((C / 4)) - 2 * C;
    f = f % 7;
    return f < 0 ? f + 7 : f;
}
//HORIZONTAL CALENDER MONTHS
void print_horizontal_months(){
    int month=0;

    cout << MONTH[month]<<"\n";
    for (int i = 0; i < 7; i++)
    {
        cout << DATE[i]<<"\t";
    }
    cout << "\n";

    int count;
    count = getcount();
    for (int k = 0; k < count; k++)
    {
        cout << "\t";
    }

    for (int i = 0; i < 12;i++){
        int divider = DIVIDER[i]+30;
        int j = 1;
        while(divider>0){
            count = count%7;
            if(count ==0)
                cout << "\n";
            cout << j<<"\t";
            j++;
            divider--;
            count++;
        }
        cout << "\n";
        month++;
        cout << MONTH[month] << "\n";
        for (int k = 0; k < 7; k++)
        {
            cout << DATE[k] << "\t";
        }
        cout << "\n";
        for (int k = 0; k < count; k++)
        {
            cout << "\t";
        }
    }
    
}
//VERTICAL MONTHS CALENDER
void print_vertical_months(){
    //get the first day and date of the month
    //generate the rest of the dates and store them 
        // use the divider
        //
    //
}
//DRIVER
int main(){
    cin >> YEAR;
    format_months()
    print_horizontal_months();
}