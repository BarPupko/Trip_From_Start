static int TripNum = 0;

#include <limits>
#include "Trip.h"
#include "Date.h"
#include "ManagementTrips.h"

using namespace std;

void deleteTrips(ManagementTrips *mts);

void AddTrip(ManagementTrips *mts);

int main() {
    ManagementTrips mts;
    int option;
    do {
        cout << "Please Select an option: \n1.Print Trips\n2.Delete Trips\n3.Add Trip\n4.Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                mts.PrintTrips();
                break;
            case 2:
                deleteTrips(&mts);
                break;
            case 3:
                AddTrip(&mts);
                break;
            case 4:
                cout << "Bye Bye!" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }while (option!= 4);
    return 0;

}//main


void deleteTrips(ManagementTrips *mts) {
    if (!mts) {
        std::cerr << "ManagementTrips pointer is null." << std::endl;
        return;
    }

    // Assuming ManagementTrips class has a method to get the total number of trips
    int totalTrips = mts->getTripNum();

    for (int i = 0; i < totalTrips; ++i) {
        // Assuming ManagementTrips class has a method to delete a trip by index or ID
        mts->deleteTrip(i);
    }

    std::cout << "All trips have been deleted." << std::endl;
}


void AddTrip(ManagementTrips *mts) {
    if (!mts) {
        std::cerr << "ManagementTrips pointer is null." << std::endl;
        return; // Handle null pointer
    }

    std::cout << "Enter details for the new trip:" << std::endl;

    char tripDesc[256]; // Assuming a sensible max length for description
    int day, month, year;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume any leftover newline
    std::cout << "Enter trip description: ";
    std::cin.getline(tripDesc, sizeof(tripDesc));

    std::cout << "Enter day, month, and year for the trip: ";
    std::cin >> day >> month >> year;

    Trip newTrip(tripDesc, day, month, year);
    *mts += newTrip; // Add the new trip to ManagementTrips instance

    std::cout << "New trip added successfully." << std::endl;
}
