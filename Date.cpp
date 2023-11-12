using namespace std;

#include "Date.h"
#include <iostream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    this->day = day;
    this->month = month;
    this->year = year;

}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int newDay) {
    if (newDay >= 1 && newDay <= 30) {
        this->day = newDay;
    } else {
        this->day = 0;
    }
}

void Date::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12) {
        this->month = newMonth;
    } else {
        this->month = 0;
    }
}

void Date::setYear(int newYear) {
    if (newYear >= 1900 && newYear <= 2020) {
        this->year = newYear;
    }else{
        newYear = 0;
    }
}

void Date::print() const {
    cout << day << "/" << month << "/" << year << endl;
}
