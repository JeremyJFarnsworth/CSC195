#pragma once
#include <string>
#include <iostream>

class Vehicle
{
public:

	enum class Types
	{
		CAR,
		PLANE,
		BOAT
	};

	
	float price;

	virtual void Read(std::ostream& ostream, std::istream& istream) {
		ostream << "Enter name: ";
		std::getline(istream >> std::ws, name);
	}
	virtual void Write(std::ostream& ostream)
	{

	};

	virtual std::string GetName() const = 0;
	virtual Types GetType() = 0;

protected:
	std::string name;

	

	

};




