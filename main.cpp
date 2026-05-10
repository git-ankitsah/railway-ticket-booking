#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class RailwayTicket
{
private:
    int trainNo;
    string passengerName;
    int age;
    string source;
    string destination;
    int seats;

public:
    void bookTicket()
    {
        cout << "\n===== Ticket Booking =====\n";

        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, passengerName);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Train Number: ";
        cin >> trainNo;

        cin.ignore();

        cout << "Enter Source Station: ";
        getline(cin, source);

        cout << "Enter Destination Station: ";
        getline(cin, destination);

        cout << "Enter Number of Seats: ";
        cin >> seats;

        ofstream file("tickets.txt", ios::app);

        file << "\nPassenger Name : " << passengerName << endl;
        file << "Age            : " << age << endl;
        file << "Train Number   : " << trainNo << endl;
        file << "Source         : " << source << endl;
        file << "Destination    : " << destination << endl;
        file << "Seats          : " << seats << endl;
        file << "-------------------------------" << endl;

        file.close();

        cout << "\nTicket Booked Successfully!\n";
    }

    void viewTickets()
    {
        ifstream file("tickets.txt");

        string line;

        cout << "\n===== All Booked Tickets =====\n";

        while(getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
};

int main()
{
    RailwayTicket r;
    int choice;

    do
    {
        cout << "\n========== Railway Ticket Booking System ==========\n";
        cout << "1. Book Ticket\n";
        cout << "2. View Tickets\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                r.bookTicket();
                break;

            case 2:
                r.viewTickets();
                break;

            case 3:
                cout << "\nThank You for Using System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}