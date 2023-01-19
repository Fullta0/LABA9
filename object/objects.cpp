#include "objects.h"


using namespace std;

Abstractcar::Abstractcar(double _fuel_level, int _milage, double _consumption, int _max_fuel) : fuel_level(_fuel_level), milage(_milage), consumption(_consumption), max_fuel(_max_fuel) {}
sedan::sedan() : Abstractcar(0, 0, 5, 50) {}
suv::suv() : Abstractcar(0, 0, 9.5, 100) {}
bus::bus() : Abstractcar(0, 0, 13.75, 230) {}

bicycle::bicycle() {}

void Abstractcar::refuel() {
	fuel_level = max_fuel;
}

bool Abstractcar::drive(double kilometrs) {
	double a = consumption * (kilometrs / 100);
	if (a > fuel_level) {
		cout << "Not enough fuel" << endl;
		return false;
	}
	else {
		milage += kilometrs;
		fuel_level -= a;
		cout << "You have traveled " << kilometrs << " km" << endl;
		return true;
	}
}

void Abstractcar::printStatus() {
	cout << "Fuel level: " << fuel_level << endl;
	cout << "Milage: " << milage << endl;
}

double Abstractcar::getFuelLevel(){
  return fuel_level;
}

double Abstractcar::getMilage(){
  return milage;
}

void bicycle::refuel() {

}

bool bicycle::drive(double kilometrs) {
	milage += kilometrs;
	cout << "You have traveled " << kilometrs << " km" << endl;
	return true;
}

void bicycle::printStatus() {
	cout << "Milage: " << milage << endl;
}

double bicycle::getMilage(){
  return milage;
}

void Route::addPoint() {
	cout << "Enter name of point: ";
	cin >> point.name;
	cout << "Enter x of point: ";
	cin >> point.x;
	cout << "Enter y of point: ";
	cin >> point.y;
	way.push_back(point);
}

void Route::addPoint (double x, double y, string n){
  point.x = x;
  point.y = y;
  point.name = n;
  way.push_back(point);
}

void Route::run(IVehicle* vehicle) {
	double kilometrs;
	if (way.size() >= 2) {
		for (int i = 0; i < way.size() - 1; i++) {
			kilometrs = sqrt(pow(way[i + 1].x - way[i].x, 2) + pow(way[i + 1].y - way[i].y, 2));
			if (vehicle->drive(kilometrs) == false) {
				vehicle->refuel();
				if (vehicle->drive(kilometrs) == false) {

					cout << "Error: not enought max fuel" << endl;
					return;
				}
			}
		}
	}
	else cout << "Error: ";
};
