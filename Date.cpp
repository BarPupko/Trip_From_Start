#include "Date.h"
#include <iostream>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setYear(int y) {
    year = y;
}

void Date::print() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}
