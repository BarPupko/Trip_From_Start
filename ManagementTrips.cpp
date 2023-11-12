#include "ManagementTrips.h"
#include "Date.h"

// Constructor
ManagementTrips::ManagementTrips() : trips(nullptr), capacity(10), numTrips(0) {
    trips = new Trip[capacity];
}

// Destructor
ManagementTrips::~ManagementTrips() {
    delete[] trips;
}

// Copy constructor
ManagementTrips::ManagementTrips(const ManagementTrips& other) : capacity(other.capacity), numTrips(other.numTrips) {
    trips = new Trip[capacity];
    for (int i = 0; i < numTrips; ++i) {
        trips[i] = other.trips[i];
    }
}

// Private method to resize the array
void ManagementTrips::resize() {
    capacity *= 2;
    Trip* newTrips = new Trip[capacity];
    for (int i = 0; i < numTrips; ++i) {
        newTrips[i] = trips[i];
    }
    delete[] trips;
    trips = newTrips;
}

ManagementTrips& ManagementTrips::operator+=(const Trip& trip) {
    // Resize if the array is full
    if (numTrips == capacity) {
        resize();
    }

    // Check for duplication
    for (int i = 0; i < numTrips; ++i) {
        if (trips[i].getDate() == trip.getDate()) {
            return *this; // Don't add if a trip with the same date exists
        }
    }

    // Add the new trip
    trips[numTrips] = trip;
    numTrips++; // Increment the count of trips

    return *this;
}

// Remove trips by date
ManagementTrips& ManagementTrips::operator-=(const Trip& trip) {
    int j = 0;
    for (int i = 0; i < numTrips; ++i) {
        if (!(trips[i].getDate() == trip.getDate())) {
            trips[j++] = trips[i];
        }
    }
    numTrips = j; // Update the number of trips
    return *this;
}

// Print trips
std::ostream& operator<<(std::ostream& os, const ManagementTrips& mt) {
    if (mt.numTrips == 0) {
        os << "The trip list is empty." << std::endl;
    } else {
        for (int i = 0; i < mt.numTrips; ++i) {
            os << "Trip " << i + 1 << ":" << std::endl;
            mt.trips[i].print();
            os << std::endl;
        }
    }
    return os;
}
