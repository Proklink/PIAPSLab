#include <iostream>
#include <vector>
#include <string>
#include "AbstractFactory.h"

class TCBuilder {


public:

	TCBuilder()  {}

	void resetTransportCompany() {}

	void addBusTransport(int num) {}
	void addTaxiTransport(int num) {}
	void addBusPassenger(int num) {}
	void addTaxiPassenger(int num) {}
	void addBusDriver(int num) {}
	void addTaxiDriver(int num) {}

	
};

class BusTCBuilder : public TCBuilder {
private:
	TransportCompany* BusTC;

public:
	BusTCBuilder() : BusTC(NULL) {}

	~BusTCBuilder() {
		if (BusTC)
			delete BusTC;
	}

	void resetTransportCompany() {
		if (BusTC)
			delete BusTC;
		BusTC = new TransportCompany();
	}

	void addBusTransport(int num) {
		for (int i = 0; i < num; i++) {
			BusTC->addTransport(new BusTransport(to_string(i)));
		}
	}
	
	void addBusPassenger(int num) {
		for (int i = 0; i < num; i++) {
			BusTC->addPassenger(new BusPassenger(to_string(i)));
		}
	}
	
	void addBusDriver(int num) {
		for (int i = 0; i < num; i++) {
			BusTC->addDriver(new BusDriver(to_string(i)));
		}
	}

	TransportCompany* getResult() {
		return BusTC;
	}

};

class TaxiTCBuilder : public TCBuilder {
private:
	TransportCompany* TaxiTC;

public:
	TaxiTCBuilder() : TaxiTC(NULL) {}

	~TaxiTCBuilder() {
		if (TaxiTC)
			delete TaxiTC;
	}

	void resetTransportCompany() {
		if (TaxiTC)
			delete TaxiTC;
		TaxiTC = new TransportCompany();
	}

	void addTaxiTransport(int num) {
		for (int i = 0; i < num; i++) {
			TaxiTC->addTransport(new TaxiTransport(to_string(i)));
		}
	}

	void addTaxiPassenger(int num) {
		for (int i = 0; i < num; i++) {
			TaxiTC->addPassenger(new TaxiPassenger(to_string(i)));
		}
	}

	void addTaxiDriver(int num) {
		for (int i = 0; i < num; i++) {
			TaxiTC->addDriver(new TaxiDriver(to_string(i)));
		}
	}

	TransportCompany* getResult() {
		return TaxiTC;
	}

};

class Director {
private:
	TCBuilder *builder;

public:
	Director(TCBuilder *b) : builder(b) {}

	~Director() {
		if (builder)
			delete builder;
	}

	void constructTransportCompany(int numPassengers, int numTransports, int numDrivers) {
		if (builder)
			cout << "Builder is NULL";
		else {
			builder->addBusDriver(numDrivers);
			builder->addBusPassenger(numPassengers);
			builder->addBusTransport(numTransports);
			builder->addTaxiDriver(numDrivers);
			builder->addTaxiPassenger(numPassengers);
			builder->addTaxiTransport(numDrivers);
		}
	}

	void changeBuilder(TCBuilder* b) {
		builder = b;
	}

};

class TransportCompany {
private:
	vector<Passenger*> passengers;
	vector<Transport*> transports;
	vector<Driver*> drivers;
public:

	void addData(TransportFactory* factory, int tr, int pass, int dr) {
		for (int i = 0; i < dr; i++) {
			drivers.push_back(factory->createDriver(to_string(i)));
		}
		for (int i = 0; i < tr; i++) {
			transports.push_back(factory->createTransport(to_string(i)));
		}
		for (int i = 0; i < pass; i++) {
			passengers.push_back(factory->createPassenger(to_string(i)));
		}
	}

	void addData(vector<Passenger*>* pass, vector<Transport*>* tr, vector<Driver*>* dr) {
		for (int i = 0; i < tr->size(); i++) {
			transports.push_back((*tr)[i]);
		}
		for (int i = 0; i < dr->size(); i++) {
			drivers.push_back((*dr)[i]);
		}
		for (int i = 0; i < pass->size(); i++) {
			passengers.push_back((*pass)[i]);
		}
	}


	void addPassenger(Passenger *passenger) {
		passengers.push_back(passenger);
	}

	void addDriver(Driver* driver) {
		drivers.push_back(driver);
	}

	void addTransport(Transport* transport) {
		transports.push_back(transport);
	}

	~TransportCompany() {
		for (int i = 0; i < passengers.size(); i++) {
			delete passengers[i];
		}
		for (int i = 0; i < transports.size(); i++) {
			delete transports[i];
		}
		for (int i = 0; i < drivers.size(); i++) {
			delete drivers[i];
		}

	}

	int boardTransports() {

		cout << "Now free " << transports.size() << " machines" << endl;

		for (int i = 0; i < transports.size(); i++) {

			for (int j = 0; j < passengers.size(); j++) {

				if (transports[i]->passengers->size() < transports[i]->maxPassengers) {
					transports[i]->passengers->push_back(passengers[j]);

					passengers.erase(passengers.begin() + j);
					j--;
				}

			}

			if (!transports[i]->driver) {
				if (drivers.size() != 0) {
					transports[i]->driver = drivers[0];

					drivers.erase(drivers.begin());
				}
				else {
					cout << "There is no driver for bus " << transports[i]->name << endl;
				}
			}

			if (transports[i]->driver && (transports[i]->passengers->size() == transports[i]->maxPassengers)) {
				cout << "The machine " << transports[i]->name << " is ready to go" << endl;

				delete transports[i];
				transports.erase(transports.begin() + i);
				i--;
			}

		}

		if (transports.size() == 0) {
			cout << "All machines is filled" << endl;
			return 1;
		}
		else {

			cout << "Unfilled transport:" << endl;
			for (int i = 0; i < transports.size(); i++) {

				cout << "Transport " << transports[i]->name << " have passengers " << transports[i]->passengers->size() <<
					"and " << (transports[i]->driver) ? "have friver" : "not have driver\n";
			}
			cout << "Unplaced passengers " << passengers.size() << endl;
			cout << "Unplaced passengers " << drivers.size() << endl;
			return 0;
		}
	}

	
};

void input(int* transportNum, int* peopleNum, int* driverNum) {
	cout << "Enter num of machines: ";
	cin >> *transportNum;
	cout << "Enter num of passengers: ";
	cin >> *peopleNum;
	cout << "Enter num of drivers: ";
	cin >> *driverNum;
}

void AbstractFactoryDemostrate() {
	BusTransportFactory busFactory;
	TaxiTransportFactory taxiFactory;
	int transportNum, peopleNum, driverNum;

	cout << "Buses:" << endl;
	input(&transportNum, &peopleNum, &driverNum);

	TransportCompany buses;
	buses.addData(&busFactory, driverNum, peopleNum, transportNum);

	cout << "Taxies:" << endl;
	input(&transportNum, &peopleNum, &driverNum);

	TransportCompany taxies;
	taxies.addData(&taxiFactory, driverNum, peopleNum, transportNum);

	int ans;
	bool exit = true;
	while (exit) {

		system("cls");
		cout << "1. Do you want to start boarding?" << endl;
		cout << "2. Add data for boarding\n";
		cout << "3. Exit\n";
		cin >> ans;

		switch (ans) {
		case 1:
			buses.boardTransports();
			taxies.boardTransports();
			break;
		case 2:
			cout << "Buses:" << endl;
			input(&transportNum, &peopleNum, &driverNum);

			buses.addData(&busFactory, transportNum, peopleNum, driverNum);

			cout << "Taxies:" << endl;
			input(&transportNum, &peopleNum, &driverNum);

			taxies.addData(&taxiFactory, transportNum, peopleNum, driverNum);

			break;
		case 3:
			exit = false;
			break;
		}
		system("pause");


	}
}

void BuilderDemostrate() {
	BusTCBuilder busBuilder;
	TaxiTCBuilder taxiBuilder;
	Director director(&busBuilder);
	int transportNum, peopleNum, driverNum;

	cout << "Buses:" << endl;
	input(&transportNum, &peopleNum, &driverNum);

	director.constructTransportCompany(peopleNum, transportNum, driverNum);
	TransportCompany *buses = busBuilder.getResult();
	
	cout << "Taxies:" << endl;
	input(&transportNum, &peopleNum, &driverNum);

	director.changeBuilder(&taxiBuilder);
	director.constructTransportCompany(peopleNum, transportNum, driverNum);
	TransportCompany *taxies = taxiBuilder.getResult();


	int ans;
	bool exit = true;
	while (exit) {

		system("cls");
		cout << "1. Do you want to start boarding?" << endl;
		cout << "2. Add data for boarding\n";
		cout << "3. Exit\n";
		cin >> ans;

		switch (ans) {
		case 1:
			buses->boardTransports();
			taxies->boardTransports();
			break;
		case 2:
			cout << "Buses:" << endl;
			input(&transportNum, &peopleNum, &driverNum);

			director.changeBuilder(&busBuilder);
			director.constructTransportCompany(peopleNum, transportNum, driverNum);
			buses = busBuilder.getResult();

			cout << "Taxies:" << endl;
			input(&transportNum, &peopleNum, &driverNum);

			director.changeBuilder(&taxiBuilder);
			director.constructTransportCompany(peopleNum, transportNum, driverNum);
			taxies = taxiBuilder.getResult();

			break;
		case 3:
			exit = false;
			break;
		}
		system("pause");


	}

	delete buses, taxies;
}

int main()
{
	


}

