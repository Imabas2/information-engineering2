#include<iostream>
#include"TimeKlass.h"
using namespace std;

    Time::Time()
    {
      second=0;
    }
    Time::Time(int nsecond)
    {
      second=nsecond;
    }
    int Time::get_hour(){
        return second/3600;
    }
    int Time::get_minut(){
        return second/60;
    }
    int Time::get_second(){
        return second;
    }
    void Time::set_second(int nSeconds){
        second = nSeconds;
    }

    Time Time::operator+(const Time rhs) const {
        int newSecond = second+rhs.second;
        return Time(newSecond);
    }

    Time Time::operator-(const Time rhs) const {
        int newSecond = 0;
        if(second>rhs.second) {
            newSecond = second-rhs.second;
        }
        else
            newSecond=rhs.second-second;
        return Time(newSecond);

    }

    Time::operator const int(){
        return second;
    }

    istream &operator>>(istream &in, Time &rhs){
        int newH = 0;
        int newM = 0;
        int newS = 0;
        char text;
        in >> newH >> text >> text >> newM >> text >> text >> newS;
        rhs.set_second(newS + (newM * 60) + (newH * 3600) );
        return in;
    };
