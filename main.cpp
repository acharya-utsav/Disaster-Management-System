#include <iostream>
#include <fstream>
#include <iomanip>
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

    void input()
    {
        cout << "\nEnter Disaster ID : ";
        cin >> disasterID;
        cin.ignore();

        cout << "Enter Disaster Type : ";
        getline(cin, disasterType);

        cout << "Enter Location : ";
        getline(cin, location);

        cout << "Enter Date : ";
        getline(cin, date);

        cout << "Enter Severity (Low/Medium/High/Critical): ";
        getline(cin, severity);

        status = "Pending";
    }

    void display()
    {
        cout<<left
            <<setw(8)<<disasterID
            <<setw(15)<<disasterType
            <<setw(18)<<location
            <<setw(15)<<severity
            <<setw(15)<<status<<endl;
    }

    int getID()
    {
        return disasterID;
    }

    string getStatus()
    {
        return status;
    }

    string getSeverity()
    {
        return severity;
    }

    void updateStatus()
    {
        int ch;

        cout<<"\n1. Pending";
        cout<<"\n2. Ongoing";
        cout<<"\n3. Resolved";
        cout<<"\nChoose Status : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            status="Pending";
            break;

        case 2:
            status="Ongoing";
            break;

        case 3:
            status="Resolved";
            break;

        default:
            cout<<"\nInvalid Choice!\n";
        }
    }

    void save(ofstream &out)
    {
        out<<disasterID<<endl;
        out<<disasterType<<endl;
        out<<location<<endl;
        out<<date<<endl;
        out<<severity<<endl;
        out<<status<<endl;
    }

    void load(ifstream &in)
    {
        in>>disasterID;
        in.ignore();

        getline(in,disasterType);
        getline(in,location);
        getline(in,date);
        getline(in,severity);
        getline(in,status);
    }
};



class RescueTeam
{
private:

    int teamID;
    string teamName;
    string leader;
    int members;
    string availability;

public:

    RescueTeam()
    {
        teamID=0;
        teamName="";
        leader="";
        members=0;
        availability="Available";
    }

    void input()
    {
        cout<<"\nEnter Team ID : ";
        cin>>teamID;
        cin.ignore();

        cout<<"Enter Team Name : ";
        getline(cin,teamName);

        cout<<"Leader Name : ";
        getline(cin,leader);

        cout<<"Number of Members : ";
        cin>>members;

        availability="Available";
    }

    void display()
    {
        cout<<left
            <<setw(8)<<teamID
            <<setw(22)<<teamName
            <<setw(18)<<leader
            <<setw(10)<<members
            <<setw(15)<<availability
            <<endl;
    }

    int getID()
    {
        return teamID;
    }

    string getAvailability()
    {
        return availability;
    }

    void assign()
    {
        availability="Assigned";
    }

    void release()
    {
        availability="Available";
    }

    void save(ofstream &out)
    {
        out<<teamID<<endl;
        out<<teamName<<endl;
        out<<leader<<endl;
        out<<members<<endl;
        out<<availability<<endl;
    }

    void load(ifstream &in)
    {
        in>>teamID;
        in.ignore();

        getline(in,teamName);
        getline(in,leader);

        in>>members;
        in.ignore();

        getline(in,availability);
    }
};



class Resource
{
private:

    int resourceID;
    string resourceName;
    int quantity;

public:

    Resource()
    {
        resourceID=0;
        resourceName="";
        quantity=0;
    }

    void input()
    {
        cout<<"\nResource ID : ";
        cin>>resourceID;
        cin.ignore();

        cout<<"Resource Name : ";
        getline(cin,resourceName);

        cout<<"Quantity : ";
        cin>>quantity;
    }

    void display()
    {
        cout<<left
            <<setw(10)<<resourceID
            <<setw(25)<<resourceName
            <<setw(10)<<quantity
            <<endl;
    }

    int getID()
    {
        return resourceID;
    }

    void save(ofstream &out)
    {
        out<<resourceID<<endl;
        out<<resourceName<<endl;
        out<<quantity<<endl;
    }

    void load(ifstream &in)
    {
        in>>resourceID;
        in.ignore();

        getline(in,resourceName);

        in>>quantity;
        in.ignore();
    }
};



class DisasterManagementSystem
{
private:

    Disaster disaster[100];
    RescueTeam team[50];
    Resource resource[100];

    int totalDisasters;
    int totalTeams;
    int totalResources;

public:

    DisasterManagementSystem()
    {
        totalDisasters=0;
        totalTeams=0;
        totalResources=0;

        loadDisaster();
        loadTeam();
        loadResource();
    }

    // File Handling
    void saveDisaster();
    void loadDisaster();

    void saveTeam();
    void loadTeam();

    void saveResource();
    void loadResource();

    // Disaster
    void reportDisaster();
    void viewDisaster();
    void searchDisaster();
    void updateDisaster();
    void deleteDisaster();

    // Team
    void addTeam();
    void viewTeam();

    // Resource
    void addResource();
    void viewResource();

    // Dashboard
    void dashboard();

    // Report
    void generateReport();

    // Menu
    void menu();
};


void DisasterManagementSystem::saveDisaster()
{
    ofstream out("disaster.txt");

    out<<totalDisasters<<endl;

    for(int i=0;i<totalDisasters;i++)
        disaster[i].save(out);

    out.close();
}

void DisasterManagementSystem::loadDisaster()
{
    ifstream in("disaster.txt");

    if(!in)
        return;

    in>>totalDisasters;
    in.ignore();

    for(int i=0;i<totalDisasters;i++)
        disaster[i].load(in);

    in.close();
}

void DisasterManagementSystem::saveTeam()
{
    ofstream out("team.txt");

    out<<totalTeams<<endl;

    for(int i=0;i<totalTeams;i++)
        team[i].save(out);

    out.close();
}

void DisasterManagementSystem::loadTeam()
{
    ifstream in("team.txt");

    if(!in)
        return;

    in>>totalTeams;
    in.ignore();

    for(int i=0;i<totalTeams;i++)
        team[i].load(in);

    in.close();
}

void DisasterManagementSystem::saveResource()
{
    ofstream out("resource.txt");

    out<<totalResources<<endl;

    for(int i=0;i<totalResources;i++)
        resource[i].save(out);

    out.close();
}

void DisasterManagementSystem::loadResource()
{
    ifstream in("resource.txt");

    if(!in)
        return;

    in>>totalResources;
    in.ignore();

    for(int i=0;i<totalResources;i++)
        resource[i].load(in);

    in.close();
}



void DisasterManagementSystem::reportDisaster()
{
    if(totalDisasters>=100)
    {
        cout<<"\nStorage Full!\n";
        return;
    }

    disaster[totalDisasters].input();
    totalDisasters++;

    saveDisaster();

    cout<<"\nDisaster Added Successfully.\n";
}

void DisasterManagementSystem::viewDisaster()
{
    if(totalDisasters==0)
    {
        cout<<"\nNo Disaster Found.\n";
        return;
    }

    cout<<"\n==============================================================\n";

    cout<<left
        <<setw(8)<<"ID"
        <<setw(15)<<"TYPE"
        <<setw(18)<<"LOCATION"
        <<setw(15)<<"SEVERITY"
        <<setw(15)<<"STATUS"<<endl;

    cout<<"==============================================================\n";

    for(int i=0;i<totalDisasters;i++)
        disaster[i].display();
}

void DisasterManagementSystem::searchDisaster()
{
    int id;
    bool found=false;

    cout<<"\nEnter Disaster ID : ";
    cin>>id;

    for(int i=0;i<totalDisasters;i++)
    {
        if(disaster[i].getID()==id)
        {
            cout<<"\n==============================================================\n";

            cout<<left
                <<setw(8)<<"ID"
                <<setw(15)<<"TYPE"
                <<setw(18)<<"LOCATION"
                <<setw(15)<<"SEVERITY"
                <<setw(15)<<"STATUS"<<endl;

            cout<<"==============================================================\n";

            disaster[i].display();

            found=true;
            break;
        }
    }

    if(!found)
        cout<<"\nRecord Not Found.\n";
}

void DisasterManagementSystem::updateDisaster()
{
    int id;
    bool found=false;

    cout<<"\nEnter Disaster ID : ";
    cin>>id;

    for(int i=0;i<totalDisasters;i++)
    {
        if(disaster[i].getID()==id)
        {
            disaster[i].updateStatus();

            saveDisaster();

            found=true;

            cout<<"\nUpdated Successfully.\n";

            break;
        }
    }

    if(!found)
        cout<<"\nRecord Not Found.\n";
}

void DisasterManagementSystem::deleteDisaster()
{
    int id;
    bool found=false;

    cout<<"\nEnter Disaster ID : ";
    cin>>id;

    for(int i=0;i<totalDisasters;i++)
    {
        if(disaster[i].getID()==id)
        {
            for(int j=i;j<totalDisasters-1;j++)
                disaster[j]=disaster[j+1];

            totalDisasters--;

            saveDisaster();

            found=true;

            cout<<"\nDeleted Successfully.\n";

            break;
        }
    }

    if(!found)
        cout<<"\nRecord Not Found.\n";
}



void DisasterManagementSystem::addTeam()
{
    if(totalTeams>=50)
    {
        cout<<"\nMaximum Team Limit Reached.\n";
        return;
    }

    team[totalTeams].input();
    totalTeams++;

    saveTeam();

    cout<<"\nRescue Team Added Successfully.\n";
}

void DisasterManagementSystem::viewTeam()
{
    if(totalTeams==0)
    {
        cout<<"\nNo Rescue Team Found.\n";
        return;
    }

    cout<<"\n===============================================================\n";

    cout<<left
        <<setw(8)<<"ID"
        <<setw(22)<<"TEAM NAME"
        <<setw(18)<<"LEADER"
        <<setw(10)<<"MEMBERS"
        <<setw(15)<<"STATUS"<<endl;

    cout<<"===============================================================\n";

    for(int i=0;i<totalTeams;i++)
        team[i].display();
}



void DisasterManagementSystem::addResource()
{
    if(totalResources>=100)
    {
        cout<<"\nMaximum Resource Limit Reached.\n";
        return;
    }

    resource[totalResources].input();

    totalResources++;

    saveResource();

    cout<<"\nResource Added Successfully.\n";
}

void DisasterManagementSystem::viewResource()
{
    if(totalResources==0)
    {
        cout<<"\nNo Resource Found.\n";
        return;
    }

    cout<<"\n==============================================\n";

    cout<<left
        <<setw(10)<<"ID"
        <<setw(25)<<"RESOURCE"
        <<setw(10)<<"QTY"<<endl;

    cout<<"==============================================\n";

    for(int i=0;i<totalResources;i++)
        resource[i].display();
}



void DisasterManagementSystem::dashboard()
{
    int pending=0;
    int ongoing=0;
    int resolved=0;

    for(int i=0;i<totalDisasters;i++)
    {
        if(disaster[i].getStatus()=="Pending")
            pending++;

        else if(disaster[i].getStatus()=="Ongoing")
            ongoing++;

        else if(disaster[i].getStatus()=="Resolved")
            resolved++;
    }

    cout<<"\n=====================================\n";
    cout<<"          DASHBOARD\n";
    cout<<"=====================================\n";

    cout<<"Total Disasters : "<<totalDisasters<<endl;
    cout<<"Pending         : "<<pending<<endl;
    cout<<"Ongoing         : "<<ongoing<<endl;
    cout<<"Resolved        : "<<resolved<<endl;

    cout<<"Total Teams     : "<<totalTeams<<endl;
    cout<<"Total Resources : "<<totalResources<<endl;
}



void DisasterManagementSystem::generateReport()
{
    ofstream out("report.txt");

    out<<"========== DISASTER REPORT ==========\n";
    out<<"Total Disasters : "<<totalDisasters<<endl;
    out<<"Total Teams     : "<<totalTeams<<endl;
    out<<"Total Resources : "<<totalResources<<endl;

    out.close();

    cout<<"\nReport Generated Successfully.\n";
}



void DisasterManagementSystem::menu()
{
    int choice;

    do
    {
        cout << "\n====================================================";
        cout << "\n      DISASTER MANAGEMENT SYSTEM";
        cout << "\n====================================================";
        cout << "\n1. Report Disaster";
        cout << "\n2. View All Disasters";
        cout << "\n3. Search Disaster";
        cout << "\n4. Update Disaster Status";
        cout << "\n5. Delete Disaster";
        cout << "\n6. Add Rescue Team";
        cout << "\n7. View Rescue Teams";
        cout << "\n8. Add Resource";
        cout << "\n9. View Resources";
        cout << "\n10. Dashboard";
        cout << "\n11. Generate Report";
        cout << "\n12. Exit";
        cout << "\n====================================================";
        cout << "\nEnter Choice : ";

        while(!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid Input! Enter Again : ";
        }

        switch(choice)
        {
            case 1:
                reportDisaster();
                break;

            case 2:
                viewDisaster();
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
                addTeam();
                break;

            case 7:
                viewTeam();
                break;

            case 8:
                addResource();
                break;

            case 9:
                viewResource();
                break;

            case 10:
                dashboard();
                break;

            case 11:
                generateReport();
                break;

            case 12:
                cout << "\nThank You For Using Disaster Management System.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    }while(choice!=12);
}


int main()
{
    DisasterManagementSystem system;

    system.menu();

    return 0;
}
