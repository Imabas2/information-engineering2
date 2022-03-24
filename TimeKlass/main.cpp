#include <iostream>
#include"TimeKlass.h"
using namespace std ;

istream &operator>>(istream &in, Time &rhs){
    int newH = 0;
    int newM = 0;
    int newS = 0;
    char text;
    in >> newH >> text >> text >> newM >> text >> text >> newS;
    rhs.set_second(newS + (newM * 60) + (newH * 3600) );
    return in;
}
ostream &operator<<(ostream &str, Time &rhs){
    int hours = rhs.get_hour();
    int minuts = rhs.get_minut()-hours*60;
    int seconds = rhs.get_second()-minuts*60-hours*3600;
    if (hours>0)
    {
        str << hours << "h:"<< minuts << "m:"<< seconds << "s";
    } else if(minuts>0)
    {
       str << minuts << "m:"<< seconds << "s";

    }
    else {
        str<<seconds << "s";
        }
    return str;
}

int main()
{
    Time t1(200);
    cout << t1 << endl; // displays 03m:20s
    Time t2;
    cin >> t2; // user enters 10h:12m:01s
    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    cout<<t3s<<endl;
    return 0;
}
