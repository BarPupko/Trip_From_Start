#include "ManagementTrips.h"
#include "Date.h"
static int numTrips1;

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
    numTrips1 = numTrips;
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
void ManagementTrips::PrintTrips() const {
    if (numTrips == 0) {
        std::cout << "The trip list is empty." << std::endl;
    } else {
        for (int i = 0; i < numTrips; ++i) {
            std::cout << "Trip " << i + 1 << ":" << std::endl;
            trips[i].print(); // Assuming Trip has a print method
            std::cout << std::endl;
        }
    }
}

void ManagementTrips::deleteTrip(int index) {
    // Check if index is valid
    if (index < 0 || index >= trips.size()) {
        std::cerr << "Invalid index." << std::endl;
        return;
    }

    // Remove the trip at the specified index
    trips.erase(trips.begin() + index);

    std::cout << "Trip at index " << index << " has been deleted." << std::endl;
}
int ManagementTrips::getTripNum() {
    return this->numTrips;
}

