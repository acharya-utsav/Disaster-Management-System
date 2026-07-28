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


    int getDisasterID()
    {
    return disasterID;
    }

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
    Disaster disaster[100];
    int totalDisasters = 0;
    int choice;

    do
    {
        cout << "\n==========================================";
        cout << "\n DISASTER MANAGEMENT SYSTEM";
        cout << "\n==========================================";
        cout << "\n1. Report New Disaster";
        cout << "\n2. View All Disasters";
        cout << "\n3. Exit";
        cout << "\n==========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            if(totalDisasters < 100)
            {
                disaster[totalDisasters].inputDisaster();
                totalDisasters++;
                cout << "\nDisaster added successfully!\n";
            }
            else
            {
                cout << "\nStorage Full!\n";
            }
            break;

        case 2:
            if(totalDisasters == 0)
            {
                cout << "\nNo disaster records found.\n";
            }
            else
            {
                cout << "\n===== ALL DISASTER RECORDS =====\n";

                for(int i = 0; i < totalDisasters; i++)
                {
                    disaster[i].displayDisaster();
                }
            }
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
