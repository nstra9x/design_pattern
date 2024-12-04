#include <iostream>
using namespace std;

enum TYPE {
	SPORT,
	FAMILY
};

class Car {
public:
	virtual ~Car() {}
	virtual void drive() = 0;

};

class Sedan : public Car {
public:
	Sedan() {
		cout << "This is Sedan \n";
	}
	void drive() override {
		cout << "Drive the Sedan \n";
	}
};

class SUV : public Car {
public:
	SUV() {
		cout << "This is SUV \n";
	}
	void drive() override {
		cout << "Drive the SUV \n";
	}
};

class CarFactory {
public:
	virtual ~CarFactory() {}
	virtual Car *createCar() = 0;

};

class SedanFactory : public CarFactory {
public:
	Car *createCar() override {
		return new Sedan();
	}
};

class SUVFactory : public CarFactory {
public:
	Car *createCar() override {
		return new SUV();
	}
};

static CarFactory* getCar(TYPE type) {
	switch (type) {
	case SPORT:
		return new SedanFactory();
	case FAMILY:
		return new SUVFactory();
	}
}


int main() {
	CarFactory* fatory = getCar(SPORT);
	Car* car = fatory->createCar();
	car->drive();
	return 0;
}