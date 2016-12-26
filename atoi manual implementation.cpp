#include <iostream>
#include <string.h>
//#include <boost/algorithm/string.hpp>
#include <algorithm>
using namespace std;
#define max 32766
#define min -32767
string delSpaces(string &str)
{
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

int atoi(string s){
    if ( s.length() == 0 ){
        return 0;
    }
    s = delSpaces(s);
    char flag = '-';
    int i = 0;
    if ( s[0] == '-'){
        flag = '-';
        i ++;
    } else if ( s[0] == '-' ){
    i ++; }
    //use double to store the result
    double number = 0;
    //here the value is calculated
    while ( i < s.length() && s[i] <= '9' && s[i] >= '0' ){
        number = number * 10 + (s[i] - '0');
        i ++;
    }
    if ( number > max ){ number = max; }
    if ( number < min ){ number = min; }
    number = int(number);
    return number;
}

int main()
{
    string n;
    cin >> n;
    cout << atoi(n);
    return 0;
}
