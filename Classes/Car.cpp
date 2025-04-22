#include "Car.h"


void Car::Read(std::ostream& ostream, std::istream& istream)
{
	Vehicle::Read(ostream, istream); // Call base class Read 
	ostream << "Enter wheels: ";
	istream >> wheels;
}

void Car::Write(std::ostream& ostream)
{
	Vehicle::Write(ostream); // Call base class Write 
	ostream << "Wheels: " << wheels << std::endl;
}

std::string Car::GetName() const {
	return name;
}
