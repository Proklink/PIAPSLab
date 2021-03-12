#include "Driver.h"


Driver::Driver(string _name) : name(_name) {}


TaxiDriver::TaxiDriver(string _name) : Driver(_name) {}

void TaxiDriver::info() {
	cout << "Taxi driver" << name << endl;
}


BusDriver::BusDriver(string _name) : Driver(_name) {}

void BusDriver::info() {
	cout << "Bus driver" << name << endl;
}
