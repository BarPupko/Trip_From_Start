#include "Trip.h"
#include <cstring>

// Initialize the static member variable
int Trip::nextTripNum = 1;

// Constructor with parameters
Trip::Trip(const char *desc, int day, int month, int year) : date(day, month, year), TripNum(nextTripNum) {
    TripDesk = new char[strlen(desc) + 1];
    strcpy(TripDesk, desc);
    nextTripNum++;
}


// Default constructor
Trip::Trip() : TripNum(nextTripNum), TripDesk(nullptr), date(Date()) {}

// Copy constructor
Trip::Trip(const Trip &other) : TripNum(other.TripNum), date(other.date) {
    if (other.TripDesk) {
        TripDesk = new char[strlen(other.TripDesk) + 1];
        strcpy(TripDesk, other.TripDesk);
    } else {
        TripDesk = nullptr;
    }
}

// Destructor
Trip::~Trip() {
    delete[] TripDesk;
}

// Getters
int Trip::getTripNum() const {
    return TripNum;
}

const char *Trip::getTripDesk() const {
    return TripDesk;
}

Date Trip::getDate() const {
    return date;
}

// Setters
void Trip::setTripNum(int num) {
    TripNum = num;
}


void Trip::setTripDesk(const char *desk) {
    delete[] TripDesk;
    if (desk) {
        TripDesk = new char[strlen(desk) + 1];
        strcpy(TripDesk, desk);
    } else {
        TripDesk = nullptr;
    }
}

// Print function
void Trip::print() const {
    std::cout << "Trip Number: " << TripNum << std::endl;
    std::cout << "Trip Description: " << (TripDesk ? TripDesk : "No Description") << std::endl;
    std::cout << "Date: ";
    date.print();
}
