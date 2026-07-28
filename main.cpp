#include <iostream>
#include <string>
using namespace std;


class Disaster
{
private:
    int disasterID;
    string disasterType;
    string location;
    string date;
    string severity;
    string status;

public:
    Disaster()
    {
        disasterID = 0;
        disasterType = "";
        location = "";
        date = "";
        severity = "";
        status = "Pending";
    }

    // Input disaster details
    void inputDisaster()
    {
        cout << "\nEnter Disaster ID: ";
        cin >> disasterID;
        cin.ignore();

        cout << "Enter Disaster Type: ";
        getline(cin, disasterType);

        cout << "Enter Location: ";
        getline(cin, location);

        cout << "Enter Date (DD/MM/YYYY): ";
        getline(cin, date);

        cout << "Enter Severity (Low/Medium/High/Critical): ";
        getline(cin, severity);

        status = "Pending";
    }

    // Display disaster details
    void displayDisaster()
    {
        cout << "\n----------------------------------";
        cout << "\nDisaster ID   : " << disasterID;
        cout << "\nType          : " << disasterType;
        cout << "\nLocation      : " << location;
        cout << "\nDate          : " << date;
        cout << "\nSeverity      : " << severity;
        cout << "\nStatus        : " << status;
        cout << "\n----------------------------------\n";
    }
};

int main()
{
    Disaster d;
    int choice;

    do
    {
        cout << "\n==========================================";
        cout << "\n DISASTER MANAGEMENT SYSTEM";
        cout << "\n==========================================";
        cout << "\n1. Report New Disaster";
        cout << "\n2. View Disaster";
        cout << "\n3. Exit";
        cout << "\n==========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                d.inputDisaster();
                break;

            case 2:
                d.displayDisaster();
                break;

            case 3:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}
