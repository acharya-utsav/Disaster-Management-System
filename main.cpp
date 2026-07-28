#include <iostream>
#include <string>
using namespace std;

//==================================================
//               DISASTER CLASS
//==================================================

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
        cout << "\n-----------------------------------------";
        cout << "\nDisaster ID : " << disasterID;
        cout << "\nType        : " << disasterType;
        cout << "\nLocation    : " << location;
        cout << "\nDate        : " << date;
        cout << "\nSeverity    : " << severity;
        cout << "\nStatus      : " << status;
        cout << "\n-----------------------------------------\n";
    }

    int getID()
    {
        return disasterID;
    }

    void updateStatus()
    {
        int choice;

        cout << "\nCurrent Status : " << status;

        cout << "\n1. Pending";
        cout << "\n2. Ongoing";
        cout << "\n3. Resolved";
        cout << "\nChoose New Status : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            status = "Pending";
            break;

        case 2:
            status = "Ongoing";
            break;

        case 3:
            status = "Resolved";
            break;

        default:
            cout << "\nInvalid Choice!\n";
            return;
        }

        cout << "\nStatus Updated Successfully!\n";
    }
};

//==================================================
//      DISASTER MANAGEMENT SYSTEM CLASS
//==================================================

class DisasterManagementSystem
{
private:
    Disaster disaster[100];
    int totalDisasters;

public:
    DisasterManagementSystem()
    {
        totalDisasters = 0;
    }

    void reportDisaster();
    void viewDisasters();
    void searchDisaster();
    void updateDisaster();
    void deleteDisaster();
    void menu();
};

//==================================================
//        MEMBER FUNCTION DEFINITIONS
//==================================================

void DisasterManagementSystem::reportDisaster()
{
    if(totalDisasters < 100)
    {
        disaster[totalDisasters].inputDisaster();
        totalDisasters++;

        cout << "\nDisaster Added Successfully!\n";
    }
    else
    {
        cout << "\nStorage Full!\n";
    }
}

void DisasterManagementSystem::viewDisasters()
{
    if(totalDisasters == 0)
    {
        cout << "\nNo Disaster Records Found!\n";
        return;
    }

    cout << "\n========== ALL DISASTERS ==========\n";

    for(int i = 0; i < totalDisasters; i++)
    {
        disaster[i].displayDisaster();
    }
}

void DisasterManagementSystem::searchDisaster()
{
    int id;
    bool found = false;

    cout << "\nEnter Disaster ID : ";
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
}

void DisasterManagementSystem::updateDisaster()
{
    int id;
    bool found = false;

    cout << "\nEnter Disaster ID : ";
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
}

void DisasterManagementSystem::deleteDisaster()
{
    int id;
    bool found = false;

    cout << "\nEnter Disaster ID : ";
    cin >> id;

    for(int i = 0; i < totalDisasters; i++)
    {
        if(disaster[i].getID() == id)
        {
            for(int j = i; j < totalDisasters - 1; j++)
            {
                disaster[j] = disaster[j + 1];
            }

            totalDisasters--;
            found = true;

            cout << "\nDisaster Deleted Successfully!\n";
            break;
        }
    }

    if(!found)
    {
        cout << "\nDisaster Record Not Found!\n";
    }
}

void DisasterManagementSystem::menu()
{
    int choice;

    do
    {
        cout << "\n==========================================";
        cout << "\n DISASTER MANAGEMENT SYSTEM";
        cout << "\n==========================================";
        cout << "\n1. Report Disaster";
        cout << "\n2. View All Disasters";
        cout << "\n3. Search Disaster";
        cout << "\n4. Update Status";
        cout << "\n5. Delete Disaster";
        cout << "\n6. Exit";
        cout << "\n==========================================";
        cout << "\nEnter Choice : ";

        cin >> choice;

        switch(choice)
        {
        case 1:
            reportDisaster();
            break;

        case 2:
            viewDisasters();
            break;

        case 3:
            searchDisaster();
            break;

        case 4:
            updateDisaster();
            break;

        case 5:
            deleteDisaster();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);
}

//==================================================
//                    MAIN
//==================================================

int main()
{
    DisasterManagementSystem system;
    system.menu();

    return 0;
}
