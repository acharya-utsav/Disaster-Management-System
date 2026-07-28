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

    int getID()
    {
        return disasterID;
    }

    void updateStatus()
    {
        int ch;
        cout << "\nCurrent Status: " << status;
        cout << "\nSelect New Status";
        cout << "\n1. Pending";
        cout << "\n2. Ongoing";
        cout << "\n3. Resolved";
        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1)
            status = "Pending";
        else if (ch == 2)
            status = "Ongoing";
        else if (ch == 3)
            status = "Resolved";
        else
        {
            cout << "\nInvalid choice!\n";
            return;
        }

        cout << "\nStatus Updated Successfully!\n";
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
        cout << "\n3. Search Disaster";
        cout << "\n4. Update Disaster Status";
        cout << "\n5. Exit";
        cout << "\n==========================================";
        cout << "\nEnter your choice: ";
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
                cout << "Invalid input! Enter again: ";
        }

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
            {
                int id;
                bool found = false;
                cout << "\nEnter Disaster ID to Search: ";
                cin >> id;
                for(int i = 0; i < totalDisasters; i++)
                {
                    if(disaster[i].getID() == id)
                    {
                        disaster[i].displayDisaster();
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "\nDisaster Record Not Found!\n";
                }
                break;
            }

            case 4:
            {
                int id;
                bool found = false;
                cout << "\nEnter Disaster ID to Update: ";
                cin >> id;
                for(int i = 0; i < totalDisasters; i++)
                {
                    if(disaster[i].getID() == id)
                        {
                            disaster[i].updateStatus();
                            found = true;
                            break;
                        }
                }
                if(!found)
                {
                    cout << "\nDisaster Record Not Found!\n";
                }
                break;
            }

            case 5:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
