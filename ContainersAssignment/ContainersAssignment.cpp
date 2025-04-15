// ContainersAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main()
{
    string weekDays[2] = { "Monday", "Tuesday" };

    for (string weekday : weekDays) {
        cout << weekday << endl;
    } // prints the array

    vector<int> numbers = { 1, 2, 3, 4, 5 };

    numbers.push_back(6); // adding 6 to the back
    numbers.push_back(7); // adding 7 to the back
    numbers.pop_back(); // removing the last item

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    } // prints the vector

    list<string> fruits = { "Banana", "Apple", "Peach"};

    fruits.push_front("Kiwi"); // adding to the front
    fruits.push_back("Tomato"); // adding to the back
    
    fruits.remove("Banana"); //  removing banana
      
    for (string fruit : fruits) {
        cout << fruit << endl;
    } // prints the list

    map<string, int> inventory = { {"Dog Food", 23}, {"Toilet Paper", 3}, { "Onions", 55 } };

    inventory.emplace("Cookies", 88);
    inventory.emplace("Coke", 80);
    inventory.emplace("Ice Cream", 8);

    if (inventory.find("Dog Food") != inventory.end()) {
        inventory["Dog Food"] += 5;  // Safely update (pulled from chat gpt)
    }

    for (std::map<std::string, int>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    } // pulled from chat gpt


    
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
