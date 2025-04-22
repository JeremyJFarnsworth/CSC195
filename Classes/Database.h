#pragma once
#include "Car.h"
#include "Plane.h"
#include <vector>

class Database
{
public:
    std::vector<Vehicle*> objects;

    ~Database() {
        for (Vehicle* obj : objects) {
            delete obj;
        }
    }

    void Create(Vehicle::Types type)
    {
        Vehicle* obj = nullptr;
        switch (type)
        {
        case Vehicle::Types::CAR:
            obj = new Car;
            break;
        case Vehicle::Types::PLANE:
            obj = new Plane;
            break;
        default:
            std::cout << "Invalid vehicle type!\n";
            return;
        }

        obj->Read(std::cout, std::cin);
        objects.push_back(obj);
    }

    void DisplayAll()
    {
        for (Vehicle* obj : objects)
        {
            obj->Write(std::cout);
        }
    }

    void Display(const std::string& name)
    {
        for (Vehicle* obj : objects)
        {
            if (obj->GetName() == name)
            {
                obj->Write(std::cout);
            }
        }
    }

    void Display(Vehicle::Types type)
    {
        for (Vehicle* obj : objects)
        {
            if (obj->GetType() == type)
            {
                obj->Write(std::cout);
            }
        }
    }
};
