#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int newMins = minutes + other.minutes;
    int newHours = hours + other.hours + newMins / 60;
    newMins %= 60;
    return Time(newHours, newMins);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    minutes += other.minutes;
    hours += other.hours + minutes / 60;
    minutes %= 60;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    return 
        hours < other.hours || 
        (hours == other.hours && minutes < other.minutes);
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return 
        hours > other.hours ||
        (hours == other.hours && minutes > other.minutes);
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return hours == other.hours && minutes == other.minutes;
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    return os << "Time { hours: " << tm.hours << ", minutes: " << tm.minutes << " }";
}
