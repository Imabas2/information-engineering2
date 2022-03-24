#include <iostream>
#pragma once

class Time{
    int hrs;
    int min;
    int sec;
public:
    Time(int s=0);

    friend std::ostream &operator<<(std::ostream &str, Time &rhs);
    friend std::istream &operator>>(std::istream &str, Time &rhs);
    Time operator+(const Time &rhs) const;
    Time operator-(const Time &rhs) const;
    Time operator*(const int &scalar) const;
    operator int();
};
