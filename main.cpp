#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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
};



class RescueTeam
{

};


class Resource
{

};


class DisasterManagementSystem
{

};


int main()
{
    cout << "==============================================\n";
    cout << " DISASTER MANAGEMENT & RESCUE SYSTEM\n";
    cout << "==============================================\n";

    return 0;
}
