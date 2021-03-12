#pragma once
#include <string>
#include <iostream>

using namespace std;

class Passenger {
public:

	string name;

	Passenger(string _name);

	virtual void info() = 0;

};

class TaxiPassenger : public Passenger {
public:

	TaxiPassenger(string _name);

	virtual void info();
};

class BusPassenger : public Passenger {
public:

	BusPassenger(string _name);

	virtual void info();
};
