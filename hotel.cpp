// These are the header files that we need for the code.

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

// The line below "using namespace std" statement makes
//it unnecessary to prefix the standard library functions with "std::"
using namespace std;

struct Reservation {
    string name;
    int roomNumber;
    int numPeople;
    bool isPaid;
};

vector<Reservation> reservations;

void addReservation() {
    Reservation newReservation;
    cout << "Enter name: ";
    getline(cin, newReservation.name);
    cout << "Enter room number: ";
    cin >> newReservation.roomNumber;
    cout << "Enter number of people: ";
    cin >> newReservation.numPeople;
    newReservation.isPaid = false;
    reservations.push_back(newReservation);
}

void displayReservations() {
    cout << "Reservations:\n";
    for (const auto& reservation : reservations) {
        cout << "Name: " << reservation.name << "\n";
        cout << "Room number: " << reservation.roomNumber << "\n";
        cout << "Number of people: " << reservation.numPeople << "\n";
        cout << "Paid: " << (reservation.isPaid ? "Yes" : "No") << "\n";
        cout << endl;
    }
}

void markAsPaid() {
    int roomNumber;
    cout << "Enter room number to mark as paid: ";
    cin >> roomNumber;
    bool foundReservation = false;
    for (auto& reservation : reservations) {
        if (reservation.roomNumber == roomNumber) {
            reservation.isPaid = true;
            foundReservation = true;
            break;
        }
    }
    if (foundReservation) {
        cout << "Reservation marked as paid.\n";
    } else {
        cout << "Reservation not found.\n";
    }
}
void intro();
int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "Choose an option:\n";
        cout << "1. Add new reservation\n";
        cout << "2. Display reservations\n";
        cout << "3. Mark reservation as paid\n";
        cout << "4. Exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                displayReservations();
                break;
            case 3:
                markAsPaid();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
            //The program ends with a return 0 statement.
    return 0;
}

        // Introduction section 
void intro(){
    cout << "\n\n\n\t     HOTEL MANAGEMENT SYSTEM";
    cout << "\n\n\n\n\t     MADE BY: OYEDIRAN DAMILOLA MUBARAKA";
    cout << "\n\n\n\n\t     MATRIC NO: H/CTE/22/0692 ";
    cout << "\n\n\n\n\t     SUPERVISOR : ENGR NZUBE";
    cout << "\n\n\n\n\t     SCHOOL : THE FEDERAL POLYTECHNIC ILARO";
    cin.get();
}