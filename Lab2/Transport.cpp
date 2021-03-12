#include "Transport.h"



Transport::Transport(string _name) : name(_name) {}

Transport::~Transport() {
	if (!passengers)
		for (int i = 0; i < passengers->size(); i++)
			delete (*passengers)[i];
	if (!driver)
		delete driver;
}


BusTransport::BusTransport(string _name) : Transport(_name)
{
	maxPassengers = 30;
	passengers = new vector<Passenger*>();
}

void BusTransport::info() {
	cout << "The bus " << name;
	if (!driver)
		cout << " have driver and";
	else
		cout << " haven't driver and ";
	if (passengers->size() < 30)
		cout << passengers->size() << " passengers" << endl;
	else
		cout << " filled" << endl;
}


TaxiTransport::TaxiTransport(string _name) : Transport(_name)
{
	maxPassengers = 4;
	passengers = new vector<Passenger*>();
}

void TaxiTransport::info() {
	cout << "The taxi " << name;
	if (!driver)
		cout << " have driver and";
	else
		cout << " haven't driver and ";
	if (passengers->size() < 4)
		cout << passengers->size() << " passengers" << endl;
	else
		cout << " filled" << endl;
}
