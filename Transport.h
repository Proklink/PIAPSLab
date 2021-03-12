#pragma once

#include <string>
#include <iostream>
#include "Driver.h"
#include "Passenger.h"
#include <vector>

using namespace std;

class Transport {
public:
	string name;
	int maxPassengers;
	vector<Passenger*> *passengers = NULL;
	Driver* driver = NULL;

	Transport(string _name);

	~Transport();

	virtual void info() = 0;

};

class BusTransport : public Transport {
public:

	BusTransport(string _name);

	virtual void info();

};

class TaxiTransport : public Transport {
public:

	TaxiTransport(string _name);

	virtual void info();
};
