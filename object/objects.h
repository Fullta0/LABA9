#ifndef OBJECTS_H
#define OBJECTS_H

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class IVehicle
{
public:
	virtual bool drive(double kilometrs) = 0;
	virtual void refuel() = 0;
	virtual void printStatus() = 0;
};

class Abstractcar: public IVehicle {
protected:
	int fuel_level, milage, consumption, max_fuel;
public:
	Abstractcar(double fuel_level, int milage, double consumption, int max_fuel);

	bool drive(double kilometrs);
	void refuel();
	void printStatus();
	double getFuelLevel();
	double getMilage();
};

class sedan : public Abstractcar {
public: sedan();
};

class suv : public Abstractcar {
public: suv();
};

class bus : public Abstractcar {
public: bus();
};

class bicycle : public IVehicle {
protected:
	int milage = 0;
public: bicycle();
	  bool drive(double kilometrs);
	  void refuel();
	  void printStatus();
	  double getMilage();
};

class Route
{
protected:
	struct RoutePoint
	{
		int x, y;
		string name;
	};

public:
	RoutePoint point;
	vector <RoutePoint> way;
	void addPoint ();
	void addPoint (double x, double y, string n);
	void run(IVehicle* vehicle);

};

#endif // OBJECTS_H
