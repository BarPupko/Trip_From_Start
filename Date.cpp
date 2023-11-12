using namespace std;

#include "Date.h"
#include <iostream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    this->month = month;

    this->day = day;

    this->year = year;


}

bool Date::operator==(const Date &other) const {

    return day == other.day && month == other.month && year == other.year;
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
    } else {
        newYear = 0;
    }
}

bool Date::isLessThan(const Date &other) const {
    // First, compare the years.
    if (year < other.year) {
        return true;
    } else if (year > other.year) {
        return false;
    }
    // If years are the same, then compare the months.
    if (month < other.month) {
        return true;
    } else if (month > other.month) {
        return false;
    }
    // If months are also the same, finally compare the days.
    if (day < other.day) {
        return true;
    }
    // If none of the above returned, then the days are either greater or equal,
    // so we return false here to say this date is NOT less than the other.
    return false;
}

// Let's compare to see if this date is greater than another date.
bool Date::isGreaterThan(const Date &other) const {
    // We can use the function we just made to help us here.
    // If the other date is NOT less than this one, then this one is greater.
    return !isLessThan(other) && !isEqualTo(other);
}

// Let's see if this date is equal to another date.
bool Date::isEqualTo(const Date &other) const {
    // Check if the year, month, and day are all the same.
    return year == other.year && month == other.month && day == other.day;
}

void Date::print() const {
    cout << getDay() << "/" << getMonth() << "/" << getYear() << endl;
}

Date::Date() {

}
