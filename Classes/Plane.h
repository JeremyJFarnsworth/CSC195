#pragma once
#include "Vehicle.h"

class Plane : public Vehicle
{
public:
	void Read(std::ostream& ostream, std::istream& istream) override;
	void Write(std::ostream& ostream) override;
	Types GetType() override { return Types::PLANE; }
	std::string GetName() const override;


protected:
	int wings;
};


