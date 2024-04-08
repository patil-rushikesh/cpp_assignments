#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

struct Seat
{
    bool is_booked;
    int pnr_number;
};

class Train
{
public:
    int train_no;
    string name;
    string source;
    string destination;
    Seat *seat_map; // array to represent seat status
    int num_seats;
    static int pnr_counter; // Static variable for generating PNR numbers

    Train(int no, string n, string s, string d, int seats) : train_no(no), name(n), source(s), destination(d), num_seats(seats)
    {
        seat_map = new Seat[num_seats]; // array to represent seat status
        for (int i = 0; i < num_seats; ++i)
        {
            seat_map[i].is_booked = false; // Initialize all seats as available
            seat_map[i].pnr_number = 0;    // Initialize all PNR numbers to 0
        }
    }

    ~Train()
    {
        delete[] seat_map;
    }

    void check_availability()
    {
        cout << "Available seats for train " << train_no << " (" << name << "):" << endl;
        for (int i = 0; i < num_seats; ++i)
        {
            if (!seat_map[i].is_booked)
            {
                cout << "Seat " << i + 1 << ": Available" << endl;
            }
            else
            {
                cout << "Seat " << i + 1 << ": Booked" << endl;
            }
        }
    }

    int book_ticket()
    {
        for (int i = 0; i < num_seats; ++i)
        {
            if (!seat_map[i].is_booked)
            {
                seat_map[i].is_booked = true;           // Book the seat
                seat_map[i].pnr_number = ++pnr_counter; // Assign PNR number
                cout << "Ticket booked successfully for seat " << i + 1 << " (PNR: " << pnr_counter << ")" << endl;
                return i + 1; // Return the seat number
            }
        }
        throw runtime_error("No available seats."); // Throw exception if no seat is available
    }

    // Method to cancel a ticket
    void cancel_ticket(int seat_no)
    {
        if (seat_no >= 1 && seat_no <= num_seats)
        {
            if (seat_map[seat_no - 1].is_booked)
            {
                seat_map[seat_no - 1].is_booked = false; // Make the seat available again
                seat_map[seat_no - 1].pnr_number = 0;    // Reset PNR number
                cout << "Ticket canceled successfully for seat " << seat_no << endl;
            }
            else
            {
                throw invalid_argument("No booking found for seat."); // Throw exception if seat is already available
            }
        }
        else
        {
            throw out_of_range("Invalid seat number."); // Throw exception if seat number is invalid
        }
    }

    // Method to check PNR status
    void check_pnr_status(int pnr)
    {
        bool found = false;
        for (int i = 0; i < num_seats; ++i)
        {
            if (seat_map[i].is_booked && seat_map[i].pnr_number == pnr)
            {
                found = true;
                cout << "PNR " << pnr << " is booked for seat " << i + 1 << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "No booking found for PNR " << pnr << endl;
        }
    }

    // Method to print the ticket
    void print_ticket(int seat_no, string passenger_name, string file_name)
    {
        ofstream file(file_name);
        if (file.is_open())
        {
            file << "PNR Number: " << seat_map[seat_no - 1].pnr_number << endl;
            file << "Train No: " << train_no << endl;
            file << "Name: " << name << endl;
            file << "Source: " << source << endl;
            file << "Destination: " << destination << endl;
            file << "Seat No: " << seat_no << endl;
            file << "Passenger Name: " << passenger_name << endl;
            file.close();
            cout << "Ticket printed successfully!" << endl;
        }
        else
        {
            cerr << "Unable to open file." << endl;
        }
    }
};

int Train::pnr_counter = 0;

int main()
{
    // Create a train with 20 seats
    Train train(101, "Express", "StationA", "StationB", 20);

    int choice;
    string passenger;

    do
    {
        cout << "1. Check Seat Availability" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Cancel Ticket" << endl;
        cout << "4. Check PNR Status" << endl;
        cout << "5. Print Ticket" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your c   `       ``````````````````QAhoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            train.check_availability();
            break;
        case 2:
            try
            {
                int seat = train.book_ticket();
                cout << "Enter passenger name: ";
                cin >> passenger;
                train.print_ticket(seat, passenger, "ticket.txt");
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                int seat;
                cout << "Enter seat number to cancel: ";
                cin >> seat;
                train.cancel_ticket(seat);
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 4:
            try
            {
                int pnr;
                cout << "Enter PNR number to check status: ";
                cin >> pnr;
                train.check_pnr_status(pnr);
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 5:
            try
            {
                int seat;
                cout << "Enter seat number to print ticket: ";
                cin >> seat;
                cout << "Enter passenger name: ";
                cin >> passenger;
                train.print_ticket(seat, passenger, "ticket.txt");
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
