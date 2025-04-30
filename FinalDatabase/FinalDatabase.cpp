// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Database.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    Vehicle::Types type;
    Database* database = new Database;
    bool quit = false;

    while (!quit)
    {
        std::cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Load\n6 - Save\n7 - Quit\n";
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1: {
            std::cout << "Enter type (0 = Car, 1 = Plane): ";
            int t;
            std::cin >> t;
            if (t >= 0 && t <= 1) {
                type = static_cast<Vehicle::Types>(t);
                database->Create(type); 
            }
            else {
                std::cout << "Invalid type.\n";
            }
            break;
        }

        case 2:
            database->DisplayAll(); 
            break;

        case 3: {
            std::cin.ignore();
            std::string name;
            std::cout << "Enter the name of the vehicle: ";
            std::getline(std::cin, name);
            database->Display(name);
            break;
        }

        case 4: {
            std::cout << "Enter type (0 for CAR, 1 for PLANE): ";
            int t;
            std::cin >> t;
            if (t >= 0 && t <= 1)
                database->Display(static_cast<Vehicle::Types>(t));
            else
                std::cout << "Invalid type.\n";
            break;
        }

        case 5:
        {
            std::cin.ignore(); // Clear newline from input buffer
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::getline(std::cin, filename);
            database->Load(filename);
            break;
        }
        case 6:
        {
            std::cin.ignore(); 
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::getline(std::cin, filename);
            database->Save(filename);
            break;
        }

        case 7:
            quit = true;
            break;

        default:
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
    delete database;
    _CrtDumpMemoryLeaks();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
