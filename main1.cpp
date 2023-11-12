static int TripNum = 0;
using namespace std;

#include "Trip.h"
#include "ManagementTrips.h"


void deleteTrips(ManagmentTrips *mts);

Trip *AddTrip(managmentTrips *mts);

int main() {
    ManagementTrips mts;
    int option;
    do {
        cout << "Please Select an option: \n1.Print Trips\n2.Delete Trips\n3.Add Trip\\n4.Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                mts.PrintTrips();
                break;
            case 2:
                deleteTrips(&mts);
                break;
            case 3:
                AddTrip(mts.GetTrips(), mts.GetSize());
                break;
            case 4:
                cout << "Bye Bye!" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }

    return 0;
}//main


void DeleteTrips(ManagementTrips *mts) {
    if (!mts) {
        return; // Handle null pointer
    }

    // Assuming you want to remove trips based on a specific date
    // For this example, let's use a placeholder date
    int day = 1, month = 1, year = 2022;
    Trip refTrip("", day, month, year); // Creating a reference trip with the target date

    *mts -= refTrip; // Use the -= operator to remove trips
}

void AddTrip(ManagementTrips *mts) {
    if (!mts) {
        return; // Handle null pointer
    }

    // Placeholder data - replace with actual data input
    const char* desc = "Sample Trip";
    int day = 1, month = 1, year = 2022;

    Trip newTrip(desc, day, month, year);
    *mts += newTrip; // Use the += operator to add the trip
}


