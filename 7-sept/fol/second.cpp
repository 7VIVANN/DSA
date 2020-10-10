#include <iostream>
#include <string>
using namespace std;
bool match(int &start,int &len,string &s,string &str){
    if(start==str.length()){
        return false;
    }
    string subs = str.substr(start , len);
    if(subs.compare(s)==0)
        return true;
    else{
        start += 1;
        return match(start, len, s, str);
    }
}
int main(){
    string str = "cathartic";
    string s = "har";
    int start = 0;
    int len = s.length();
    string r = match(start, len, s, str)==true?"true":"false";
    cout << r;
}