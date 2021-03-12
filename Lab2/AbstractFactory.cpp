#include "AbstractFactory.h"


 Transport* BusTransportFactory::createTransport(string _name) {
	return new BusTransport(_name);
}
 Passenger* BusTransportFactory::createPassenger(string name) {
	return new BusPassenger(name);
}
 Driver* BusTransportFactory::createDriver(string name) {
	return new BusDriver(name);
}


 Transport* TaxiTransportFactory::createTransport(string _name) {
	return new TaxiTransport(_name);
}
 Passenger* TaxiTransportFactory::createPassenger(string name) {
	return new TaxiPassenger(name);
}
 Driver* TaxiTransportFactory::createDriver(string name) {
	return new TaxiDriver(name);
}