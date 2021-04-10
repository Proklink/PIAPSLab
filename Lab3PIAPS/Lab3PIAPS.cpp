#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


class AirlineUser {
public: 
	AirlineUser() {}

    virtual int getLuggageWeight() = 0;

	virtual ~AirlineUser() {}

};

class Passenger : public AirlineUser {
private:
	int LuggageWeight;
public:

    Passenger()  {	
		LuggageWeight  = rand() % 56 + 5;
	}

    virtual int getLuggageWeight() {
        return LuggageWeight;
    }

	virtual ~Passenger() {}
        
};

class Pilot : public AirlineUser {
public:

    Pilot() {}

    virtual int getLuggageWeight() {
        return 0;
    }

	virtual ~Pilot() {}

};

class Stewardess : public AirlineUser {
public:

    Stewardess() {}

    virtual int getLuggageWeight() {
        return 0;
    }

	virtual ~Stewardess() {}

};


class CompositeUser : public AirlineUser {		
protected:
	vector<AirlineUser *> users;
public:

	CompositeUser() {}

	void addUser(AirlineUser *user) {
		users.push_back(user);
	}

	virtual int getLuggageWeight() {
		int totalWeight = 0;
		for (AirlineUser *u : users)
			totalWeight += u->getLuggageWeight();
		return totalWeight;
	}

	int getUsersNum() {
		return users.size();
	}

	~CompositeUser() {
		for (AirlineUser *u : users)
			delete u;
	}

};

class FirstClass : public CompositeUser {
public:
	FirstClass() {}
};

class BuisnessClass : public CompositeUser {
private:
	int freeLuggage = 35;
public:
	BuisnessClass() {}

};

class EconomyClass : public CompositeUser {
private:
	int freeLuggage = 20;
public:
	EconomyClass() {}

	void removedLuggage(int needToRemoveNum) {
		int luggage = 0;
		int i = 0;

		while (luggage < needToRemoveNum) {
			luggage += users[i]->getLuggageWeight();
			cout << "User " << i << " have " << users[i]->getLuggageWeight() << endl;
			i++;
		}
	}
};

class Plane : public CompositeUser {
public:
	Plane() {}

	int getFirstClassPassNum() {

		for (int i = 0; i < users.size(); i++) {
			FirstClass* firstClass = dynamic_cast<FirstClass*>(users[i]);
			if (firstClass)
				return firstClass->getUsersNum();
		}
		return 0;
	}

	int getBuisnessClassPassNum() {
		for (int i = 0; i < users.size(); i++) {
			BuisnessClass* firstClass = dynamic_cast<BuisnessClass*>((AirlineUser *)users[i]);
			if (firstClass)
				return firstClass->getUsersNum();
		}
		return 0;
	}

	int getEconomyClassPassNum() {
		for (int i = 0; i < users.size(); i++) {
			EconomyClass* firstClass = dynamic_cast<EconomyClass*>((AirlineUser*)users[i]);
			if (firstClass)
				return firstClass->getUsersNum();
		}
		return 0;
	}

	int getPilotsNum() {
		int count = 0;

		for (int i = 0; i < users.size(); i++) {
			Pilot* pilot = dynamic_cast<Pilot*>((AirlineUser*)users[i]);
			if (pilot)
				count++;
		}
		return count;
	}

	int getStuwardessesNum() {
		int count = 0;

		for (int i = 0; i < users.size(); i++) {
			Stewardess* pilot = dynamic_cast<Stewardess*>((AirlineUser*)users[i]);
			if (pilot)
				count++;
		}
		return count;
	}

	int getPassNum() {
		int count = 0;

		for (int i = 0; i < users.size(); i++) {
			Passenger* pilot = dynamic_cast<Passenger*>((AirlineUser*)users[i]);
			if (pilot)
				count++;
		}
		return count;
	}

	int getFirstClassLuggage() {

		for (int i = 0; i < users.size(); i++) {
			FirstClass* firstClass = dynamic_cast<FirstClass*>((AirlineUser*)users[i]);
			if (firstClass)
				return firstClass->getLuggageWeight();
		}
		return 0;
	}

	int getBuisnessClassLuggage() {
		for (int i = 0; i < users.size(); i++) {
			BuisnessClass* firstClass = dynamic_cast<BuisnessClass*>((AirlineUser*)users[i]);
			if (firstClass)
				return firstClass->getLuggageWeight();
		}
		return 0;
	}

	int getEconomyClassLuggage() {
		for (int i = 0; i < users.size(); i++) {
			EconomyClass* firstClass = dynamic_cast<EconomyClass*>((AirlineUser*)users[i]);
			if (firstClass)
				return firstClass->getLuggageWeight();
		}
		return 0;
	}

	void infoAboutRemovedLuggage(int luggage) {
		for (int i = 0; i < users.size(); i++) {
			EconomyClass* firstClass = dynamic_cast<EconomyClass*>((AirlineUser*)users[i]);
			if (firstClass)
				firstClass->removedLuggage(luggage);
		}
	}

};

class AirlineCompany {
private:
	int maxWeight = 0;
	
	vector<Stewardess *> stewardesses;
	vector<Pilot *> pilots;

	vector<FirstClass *> firstClasses;
	vector<BuisnessClass *> buisnessClasses;
	vector<EconomyClass *> economyClasses;

	vector<Plane *> planes;

public: 

	AirlineCompany(int maxWeight) : maxWeight(maxWeight) {}

	void setMaxWeight(int mw) {
		maxWeight = mw;
	}

	void addPlanes(int pn) {
		for (int i = 0; i < pn; i++)
			planes.push_back(new Plane());
	}

	void addStewardesses(int num) {
		for (int i = 0; i < num; i++) 
			stewardesses.push_back(new Stewardess());
	}

	void addPilots(int num) {
		for (int i = 0; i < num; i++)
			pilots.push_back(new Pilot());
	}

	void addFirstClass() {
		FirstClass* first = new FirstClass;

		for (int i = 0; i < 10; i++)
			first->addUser(new Passenger());

		firstClasses.push_back(first);
	}

	void addBuisnessClass() {
		BuisnessClass* buisness = new BuisnessClass;

		for (int i = 0; i < 20; i++)
			buisness->addUser(new Passenger());

		buisnessClasses.push_back(buisness);
	}

	void addEconomyClass() {
		EconomyClass *economy = new EconomyClass;

		for (int i = 0; i < 150; i++)
			economy->addUser(new Passenger());

		economyClasses.push_back(economy);
	}

	void addData(int* planesNum, int* stewNum, int* pilotsNum, int* firstCNum, int* buisnessCNum, int* economyCNum) {
		addPlanes(*planesNum);
		addStewardesses(*stewNum);
		addPilots(*pilotsNum);
		for (int i = 0; i < *firstCNum; i++)
			addFirstClass();
		for (int i = 0; i < *buisnessCNum; i++)
			addBuisnessClass();
		for (int i = 0; i < *economyCNum; i++)
			addEconomyClass();
	}

	~AirlineCompany() {

		for (Stewardess *u : stewardesses)
			delete u;

		for (Pilot *u : pilots)
			delete u;

		for (FirstClass*u : firstClasses)
			delete u;

		for (BuisnessClass*u : buisnessClasses)
			delete u;

		for (EconomyClass*u : economyClasses)
			delete u;

		for (Plane* u : planes)
			delete u;

	}

	void boardPlanes() {

		for (int j = 0; j < planes.size(); j++) {

			int num = planes[j]->getPilotsNum();
			for (int i = 0; i < 2 - num; i++)
				if (pilots.size() != 0) {
					planes[j]->addUser(pilots[0]);
					pilots.erase(pilots.begin());
				}
			
			num = planes[j]->getStuwardessesNum();
			for (int i = 0; i < 6 - num; i++)
				if (stewardesses.size() != 0) {
					planes[j]->addUser(stewardesses[0]);
					stewardesses.erase(stewardesses.begin());
				}
			

			if (planes[j]->getFirstClassPassNum() == 0)
				if (firstClasses.size() != 0) {
					planes[j]->addUser((AirlineUser*)firstClasses[0]);
					firstClasses.erase(firstClasses.begin());
				}

			if (planes[j]->getBuisnessClassPassNum() == 0)
				if (buisnessClasses.size() != 0) {
					planes[j]->addUser((AirlineUser*)buisnessClasses[0]);
					buisnessClasses.erase(buisnessClasses.begin());
				}

			if (planes[j]->getEconomyClassPassNum() == 0)
				if (economyClasses.size() != 0) {
					planes[j]->addUser((AirlineUser*)economyClasses[0]);
					economyClasses.erase(economyClasses.begin());
				}
		}

	}

	void showBoardingState() {		
		system("cls");

		for (int i = 0; i < planes.size(); i++) {

			cout << "Plane " << i << ":" << endl;

			int totalWeight = planes[i]->getLuggageWeight();
			int BuisnessClassPassNum = planes[i]->getBuisnessClassPassNum();
			int EconomyClassPassNum = planes[i]->getEconomyClassPassNum();
			int FirstClassPassNum = planes[i]->getFirstClassPassNum();
			int PilotsNum = planes[i]->getPilotsNum();
			int StuwardessesNum = planes[i]->getStuwardessesNum();

			cout << "Total weight " << totalWeight << endl;

			if ((BuisnessClassPassNum != 0) &&
				(EconomyClassPassNum != 0) &&
				(FirstClassPassNum != 0) &&
				(PilotsNum == 2) &&
				(StuwardessesNum == 6) && (totalWeight <= maxWeight)) {
				cout << "The plane is ready to go\n";
			}
			else {
				cout << "The plane is not ready to go\n";

				if (totalWeight > maxWeight)
					cout << "The plane have weight overload\n";

				cout << "The plane have:\n";
				if (BuisnessClassPassNum != 0)
					cout << "Filled buisness class with " << planes[i]->getBuisnessClassLuggage() << " luggage weight\n";
				else
					cout << "Unfilled buisness class \n";

				if (EconomyClassPassNum != 0)
					cout << "Filled economy class with " << planes[i]->getEconomyClassLuggage() << " luggage weight\n";
				else
					cout << "Unfilled economy class \n";

				if (FirstClassPassNum != 0)
					cout << "Filled first class with " << planes[i]->getFirstClassLuggage() << " luggage weight\n";
				else
					cout << "Unfilled first class \n";

				//if (PilotsNum != 2)
					cout << PilotsNum << " pilots \n";

				//if (StuwardessesNum != 6)
					cout << StuwardessesNum << " stuwardesses\n";

				int lug = planes[i]->getEconomyClassLuggage();
				if (totalWeight > maxWeight)
					if ((totalWeight - lug) < maxWeight) {
						cout << "People whose luggage can be removed from the flight: \n";

						planes[i]->infoAboutRemovedLuggage(totalWeight - maxWeight);
					}

			}	
			cout << endl << endl;
		}	
	}
};

void input(int* planesNum, int* stewNum, int* pilotsNum, int* firstCNum, int* buisnessCNum, int* economyCNum) {
	cout << "Enter num of planes: ";
	cin >> *planesNum;
	cout << "Enter num of stewardesses: ";
	cin >> *stewNum;
	cout << "Enter num of pilots: ";
	cin >> *pilotsNum;
	cout << "Enter num of firstClasses: ";
	cin >> *firstCNum;
	cout << "Enter num of buisnessClasses: ";
	cin >> *buisnessCNum;
	cout << "Enter num of economyClasses: ";
	cin >> *economyCNum;
}

void CompositeDemostrate() {
	
	AirlineCompany acompany(5700);
	int planesNum, stewNum, pilotsNum, firstCNum, buisnessCNum, economyCNum;

	/*planesNum = 3;
	stewNum = 12;
	pilotsNum = 3;
	firstCNum = 3;
	buisnessCNum = 3;
	economyCNum = 3;*/

	input(&planesNum, &stewNum, &pilotsNum, &firstCNum, &buisnessCNum, &economyCNum);
	acompany.addData(&planesNum, &stewNum, &pilotsNum, &firstCNum, &buisnessCNum, &economyCNum);


	int ans;
	bool exit = true;
	while (exit) {

		system("cls");
		cout << "1. Start boarding" << endl;
		cout << "2. Add data for boarding\n";
		cout << "3. Exit\n";
		cin >> ans;

		switch (ans) {
		case 1:
			acompany.boardPlanes();
			acompany.showBoardingState();
			break;
		case 2:
			input(&planesNum, &stewNum, &pilotsNum, &firstCNum, &buisnessCNum, &economyCNum);
			acompany.addData(&planesNum, &stewNum, &pilotsNum, &firstCNum, &buisnessCNum, &economyCNum);
			break;
		case 3:
			exit = false;
			break;
		}
		system("pause");


	}
}


int main()
{

	srand(time(NULL));
	CompositeDemostrate();
}
