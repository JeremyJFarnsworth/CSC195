#include "Plane.h"


void Plane::Read(std::ostream& ostream, std::istream& istream)
{
    Vehicle::Read(ostream, istream); 
    ostream << "Enter number of wings: ";
    istream >> wings;
}


void Plane::Write(std::ostream& ostream)
{
    Vehicle::Write(ostream);
    ostream << "Wings: " << wings << std::endl;
}


void Plane::Read(std::ifstream& istream)
{
    Vehicle::Read(istream); 
    istream >> wings;
    istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}


void Plane::Write(std::ofstream& ostream)
{
    Vehicle::Write(ostream); 
    ostream << wings << '\n';
}


std::string Plane::GetName() const
{
    return name; 
}
