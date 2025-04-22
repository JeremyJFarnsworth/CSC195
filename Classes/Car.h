#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;
	Types GetType() override { return Types::CAR; }
	std::string GetName() const override;



protected:
	int wheels;
};


