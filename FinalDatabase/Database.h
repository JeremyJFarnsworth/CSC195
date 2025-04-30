#pragma once
#include "Car.h"
#include "Plane.h"
#include <vector>
#include <fstream>
#include <memory>

class Database
{
public:
    std::vector<std::unique_ptr<Vehicle>> objects;

    void Create(Vehicle::Types type)
    {
        std::unique_ptr<Vehicle> vehicle;

        if (type == Vehicle::Types::CAR) {
            vehicle = std::make_unique<Car>();
        }
        else if (type == Vehicle::Types::PLANE) {
            vehicle = std::make_unique<Plane>();
        }
        else {
            std::cout << "Unsupported type.\n";
            return;
        }

        std::cin >> *vehicle; 
        objects.push_back(std::move(vehicle));
    }

    void DisplayAll()
    {
        for (const auto& obj : objects)
        {
            std::cout << *obj << "\n"; 
        }
    }

    void Display(const std::string& name)
    {
        for (const auto& obj : objects)
        {
            if (obj->GetName() == name)
            {
                std::cout << *obj << "\n";
            }
        }
    }

    void Display(Vehicle::Types type)
    {
        for (const auto& obj : objects)
        {
            if (obj->GetType() == type)
            {
                std::cout << *obj << "\n";
            }
        }
    }

    void Save(const std::string& filename)
    {
        std::ofstream out(filename);
        if (!out) {
            std::cerr << "Failed to open file for saving.\n";
            return;
        }

        for (const auto& obj : objects)
        {
            out << static_cast<int>(obj->GetType()) << '\n'; 
            out << *obj; 
        }
    }

    void Load(const std::string& filename)
    {
        std::ifstream in(filename);
        if (!in) {
            std::cerr << "Failed to open file for loading.\n";
            return;
        }

        objects.clear(); 

        int typeInt;
        while (in >> typeInt)
        {
            auto type = static_cast<Vehicle::Types>(typeInt);
            std::unique_ptr<Vehicle> vehicle;

            if (type == Vehicle::Types::CAR) {
                vehicle = std::make_unique<Car>();
            }
            else if (type == Vehicle::Types::PLANE) {
                vehicle = std::make_unique<Plane>();
            }
            else {
                std::cerr << "Unknown type found in file.\n";
                break;
            }

            in >> *vehicle; 
            objects.push_back(std::move(vehicle));
        }
    }


};
