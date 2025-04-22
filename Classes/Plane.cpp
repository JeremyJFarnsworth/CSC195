#include "Plane.h"

void Plane::Read(std::ostream& ostream, std::istream& istream)
{
	Vehicle::Read(ostream, istream); // Call base class Read 
	ostream << "Enter wings: ";
	istream >> wings;
}

void Plane::Write(std::ostream& ostream)
{
	Vehicle::Write(ostream); // Call base class Write 
	ostream << "Wings: " << wings << std::endl;
}

std::string Plane::GetName() const {
	return name;
}