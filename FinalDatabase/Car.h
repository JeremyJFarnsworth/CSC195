#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
    
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;

    
    void Read(std::ifstream& istream) override;
    void Write(std::ofstream& ostream) override;

    
    Types GetType() override { return Types::CAR; }

    
    std::string GetName() const override;

protected:
    int wheels = 0;  
};
