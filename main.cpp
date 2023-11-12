#include "Trip.h"

using namespace std;
static int TripNum = 0;

bool isEmpty(int size);

void Print(Trip *arr, int size);

void EditTrip(Trip *arr, int size);

Trip *AddTrip(Trip *arr, int &size);

int main() {
    int option;
    Trip *arr = new Trip[0];
    int size = 0;
    do {
        cout << "\nPlease Select an Option:\n1.Print Trips\n2.Edit Trips\n3.Add Trip\n4.Exit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                Print(arr, size);
                break;
            case 2:
                EditTrip(arr, size);
                break;
            case 3:
                arr = AddTrip(arr, size);
                break;
            case 4:
                cout << "bye bye! " << endl;
                break;
            default:
                cout << "invalid option" << endl;
                break;
        }//end of switch
    } while (option != 4);
    return 0;
}//main


bool isEmpty(int size) {
    return size == 0;
}

void Print(Trip *arr, int size) {
    if (isEmpty(size)) {
        std::cout << "There are no trips to print." << std::endl;
    } else {
        for (int i = 0; i < size; ++i) {
            arr[i].print();
        }
    }
}

void EditTrip(Trip *arr, int size) {
    if (isEmpty(size)) {
        std::cout << "There are no trips to edit." << std::endl;
        return;
    }

    int tripNum;
    std::cout << "Enter the number of the trip you wish to edit: ";
    std::cin >> tripNum;

    for (int i = 0; i < size; ++i) {
        if (arr[i].getTripNum() == tripNum) {
            char newDesc[256]; // assuming a sensible max length
            int newDay, newMonth, newYear;

            std::cout << "Enter new description for trip number " << tripNum << ": ";
            std::cin.ignore(); // to consume any leftover newline
            std::cin.getline(newDesc, sizeof(newDesc));

            std::cout << "Enter new day, month, and year for trip number " << tripNum << ": ";
            std::cin >> newDay >> newMonth >> newYear;

            arr[i].setTripDesk(newDesc);
            std::cout << "Trip number " << tripNum << " has been updated." << std::endl;
            return;
        }
    }

    std::cout << "Trip number " << tripNum << " not found." << std::endl;
}

Trip *AddTrip(Trip *arr, int &size) {
    std::cout << "Enter details for the new trip:" << std::endl;

//    int tripNum;
    char tripDesc[256]; // assuming a sensible max length for description
    int day, month, year;
//    std::cout << "Enter trip number: ";
//    std::cin >> tripNum;
    std::cin.ignore(); // to consume any leftover newline
    std::cout << "Enter trip description: ";
    std::cin.getline(tripDesc, sizeof(tripDesc));
    std::cout << "Enter day, month, and year for the trip: " << endl;
    std::cin >> day >> month >> year;

    Trip *newArr = new Trip[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = Trip(tripDesc, day, month, year);
    ++TripNum;
    size++;

    delete[] arr;
    std::cout << "New trip added successfully." << std::endl;
    return newArr;
}
