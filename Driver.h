#pragma once
#include <string>
#include <iostream>

using namespace std;

class Driver {
public:

	string name;

	virtual void info() = 0;

	Driver(string _name);

};

class TaxiDriver : public Driver {
public:

	TaxiDriver(string _name);

	virtual void info();
};

class BusDriver : public Driver {
public:

	BusDriver(string _name);

	virtual void info();
};