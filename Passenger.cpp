#include "Passenger.h"



Passenger::Passenger(string _name) : name(_name) {}


TaxiPassenger::TaxiPassenger(string _name) : Passenger(_name) {}

void TaxiPassenger::info() {
	cout << "Taxi passenger" << name << endl;
}



BusPassenger::BusPassenger(string _name) : Passenger(_name) {}

void BusPassenger::info() {
	cout << "Bus passenger" << name << endl;
}
