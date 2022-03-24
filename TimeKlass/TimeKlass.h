#include<iostream>
#pragma once

using namespace std;
class Time
{
    int second=0;
public:
    Time();
    Time(int nsecond);

    int get_hour();
    int get_minut();
    int get_second();
    void set_second(int nSeconds);
    Time operator+(const Time rhs) const ;
    Time operator-(const Time rhs) const;
    operator const int();


};

