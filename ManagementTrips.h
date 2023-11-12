#ifndef MANAGEMENTTRIPS_H
#define MANAGEMENTTRIPS_H

#include "Trip.h"
#include <iostream>

class ManagementTrips {
private:
    int TripNum;

    Trip* trips;       // Dynamic array of trips
    int capacity;      // Total capacity of the array
    int numTrips;      // Current number of trips

    void resize();     // Private helper method to resize the array when needed

public:

    ManagementTrips(); // Constructor
    ~ManagementTrips(); // Destructor
    ManagementTrips(const ManagementTrips& other); // Copy constructor

    ManagementTrips& operator+=(const Trip& trip); // Add trip
    ManagementTrips& operator-=(const Trip& trip); // Remove trips by date
    void PrintTrips() const; // Declaration of PrintTrips
    friend std::ostream& operator<<(std::ostream& os, const ManagementTrips& mt); // Print trips
    int getTripNum();

    void deleteTrip(int index);
};

#endif // MANAGEMENTTRIPS_H