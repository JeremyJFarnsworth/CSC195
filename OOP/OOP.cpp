// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
//#include "Animal.h"  dont need any longer since animal is being called in dog
#include "Dog.h"
#include "Snake.h"
using namespace std;

int main()
{
    //commented out since animal class is abstract now
    //Animal animal; // instance has allocated memory on stack - no "new" keyword

    //animal.Travel();

    //Dog dog;

    //dog.Travel();

    //Animal* prtAnimal = new Animal;

    //(*prtAnimal).Travel();
    //prtAnimal->Travel();  // this does the same thing

    //Animal* ptrDog = new Dog;
    //ptrDog->Travel();

    //cout << animal.GetLimbs() << endl;

    //{
    //    Animal* ptrAnim = new Animal;

    //} // once out of scope, deletes ptrAnim so no further use is available

    Snake python;
    python.Travel();
    python.Speak();

    Dog fido;
    fido.Speak();
    fido.Travel();

    // containers to store class instances
    vector<Animal*> animals;
    animals.push_back(new Dog);
    animals.push_back(new Dog);
    animals.push_back(new Snake);

    cout << "--------------------" << endl;

    // iterate to implement methods
    for (Animal* ani : animals)
    {
        ani->Speak();
    }

    for (Animal* ani : animals) 
    {
        delete ani; // deallocating heap memory for each instance
    }

    animals.clear(); // deleting out pointers in vector that are pointing to nothing
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
