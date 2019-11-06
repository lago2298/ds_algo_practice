// Example of Encapsulation

#include <iostream>
using std::cout;

class Car {
	// Data members (by default private)
	char make[20];
	char model[20];
	int year;
	int weight;

public:
	// Functions
	void brake() {
		cout << "Braking";
	}
	void slowDown() {

	}
};

int main()
{
	Car Ford;
	Ford.brake();
	return 0;
}