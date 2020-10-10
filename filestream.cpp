#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream file("input.txt");
    string s;
    string s2 = "";
    while (getline(file, s))
    {
        int n = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == ' ')
            {
                // s2 += c;
                s2 += "tab";
            }
            else
            {
                s2 += c;
            }
        }
        s2 += "line";
    }
    ofstream output("output.txt");
    output << s2;
    file.close();
    output.close();
}
