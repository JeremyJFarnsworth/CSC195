#include "Car.h"


void Car::Read(std::ostream& ostream, std::istream& istream)
{
    Vehicle::Read(ostream, istream); 
    ostream << "Enter number of wheels: ";
    istream >> wheels;
}


void Car::Write(std::ostream& ostream)
{
    Vehicle::Write(ostream); 
    ostream << "Wheels: " << wheels << std::endl;
}


void Car::Read(std::ifstream& istream)
{
    Vehicle::Read(istream);
    istream >> wheels;
    istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}


void Car::Write(std::ofstream& ostream)
{
    Vehicle::Write(ostream); 
    ostream << wheels << '\n';
}


std::string Car::GetName() const
{
    return name; 
}
