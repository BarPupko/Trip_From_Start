#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include "Date.h" // Include the Date class header

class Trip {
private:
    int TripNum;
    char* TripDesk;
    Date date;
    static int nextTripNum;

public:
    Trip(const char *desc, int day, int month, int year);
    Trip();
    Trip(const Trip& other);
    ~Trip();

    int getTripNum() const;
    const char* getTripDesk() const;
    Date getDate() const;

    void setTripNum(int num);
    void setTripDesk(const char* desk);

    void print() const;
};

#endif // TRIP_H
