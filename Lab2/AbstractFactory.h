#pragma once

#include "Transport.h"


using namespace std;


class TransportFactory {
public:
	virtual Transport* createTransport(string _name) = 0;
	virtual Passenger* createPassenger(string name) = 0;
	virtual Driver* createDriver(string nam) = 0;
};

class BusTransportFactory : public TransportFactory {
public:
	virtual Transport* createTransport(string _name);
	virtual Passenger* createPassenger(string name);
	virtual Driver* createDriver(string name);

};

class TaxiTransportFactory : public TransportFactory {
public:
	virtual Transport* createTransport(string _name);
	virtual Passenger* createPassenger(string name);
	virtual Driver* createDriver(string name);

};