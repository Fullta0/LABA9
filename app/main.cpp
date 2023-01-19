#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "..\objects\objects.h"

int main(int argc, char* argv[])
{
    IVehicle* vehicles[4] = { new sedan, new suv, new bus, new bicycle };
    Route marshrut;
    int n;

    cout << "Arguments count: " << argc << endl;
    for (int i = 0; i < argc; ++i)
        cout << i << ": " << argv[i] << "\n";

    if (argc < 2) {
        cout << "Error: not enought arguments" << endl;
        return 1;
    };

    sedan Ass;

    ifstream A(argv[1]);

    if (A.is_open()) {
        while (!A.eof()) {
            A >> marshrut.point.x >> marshrut.point.y >> marshrut.point.name;
            marshrut.way.push_back(marshrut.point);
        }
    }


    //cout << "Enter, how many points do you want to add: ";
    //cin >> n;
    //cout << endl;
    //for (int j = 0; j < n; j++) {
    //    cout << "Point " << j + 1 << ": " << endl;
    //    marshrut.addPoint();
    //}
    for (int i = 0; i < 4; i++) {
        IVehicle* vehicle = vehicles[i];
        vehicle->printStatus();
        marshrut.run(vehicle);
        vehicle->printStatus();
        //vehicle->refuel();
        //vehicle->printStatus();
        //vehicle->drive(120);
        //vehicle->printStatus();
        //vehicle->drive(420);
        //vehicle->printStatus();
        //vehicle->drive(500);
        //vehicle->refuel();
        //vehicle->printStatus();
        //vehicle->drive(300);
        //vehicle->printStatus();
        delete vehicle;
        cout << endl;
    }
    return 0;
}


