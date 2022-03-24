#include <iostream>
#include <copyAD.h>

Time::Time(int s){
    hrs = s/3600;
    s = s-(hrs*3600);
    min = s/60;
    s = s-(min*60);
    sec = s;
}


std::ostream &operator<<(std::ostream &str, Time &rhs)
{
    if(rhs.hrs!=0)
        str << rhs.hrs << "h";
    if(rhs.min!=0)
        str << rhs.min << "m";
    if(rhs.sec!=0)
        str << rhs.sec << "s";
    return str;
}

std::istream &operator>>(std::istream &str, Time &rhs)
{
    std:: cout << "Enter number of hours:";
    str >> rhs.hrs;
    std:: cout << "Enter number of minutes:";
    str >> rhs.min;
    std:: cout << "Enter number of seconds:";
    str >> rhs.sec;

    return str;
}

Time Time::operator+(const Time &rhs) const {
 return Time( ((hrs+rhs.hrs)*3600)+((min+rhs.min)*60) + sec+rhs.sec  );
}

Time Time::operator-(const Time &rhs) const {
 return Time( ((hrs-rhs.hrs)*3600)+((min-rhs.min)*60) + sec-rhs.sec  );
}

Time Time::operator*(const int &scalar) const {
    return Time( ((sec+(min*60)+(hrs*3600))*scalar) );
}

Time::operator int(){
    return int(sec+(min*60)+(hrs*3600));
}
