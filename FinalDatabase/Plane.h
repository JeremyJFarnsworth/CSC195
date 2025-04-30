#pragma once
#include "Vehicle.h"
#include <limits>


class Plane : public Vehicle
{
public:
    
    void Read(std::ostream& ostream, std::istream& istream) override;

    
    void Write(std::ostream& ostream) override;

    
    void Read(std::ifstream& istream) override;

    
    void Write(std::ofstream& ostream) override;

    
    Types GetType() override { return Types::PLANE; }

    
    std::string GetName() const override;

protected:
    int wings = 0;
};
