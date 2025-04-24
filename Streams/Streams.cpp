// Streams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Reasons to pas by reference
// For classes like ostream/istream, cannot create copies, so pass by reference
// Ensure manipulation of variables inside the main method
// Avoid creating copies for large datatypes (resources/time efficient)
// Rule of thumb: use pass-by-reference whenever possible 
// exception: Cannot point to nothing, so if parameter needs to point to a null value, then use a pointer instead

void Write(const string& text, ostream& ostream)
{
    // value remains consistent througout execution by adding const, protects against overriding.
    ostream << text << endl;
}
//overloading moethods - same name different parameters
void Write(const vector<int> numbers, ofstream& ostream)
{
    for (int n : numbers)
    {
        ostream << n << endl;
    }
}

void Read(string& text, ifstream& istream) 
{
    istream >> text;
}

void Read(vector<int>& numbers, ifstream& istream)
{
    while (!istream.eof())
    {
        int n;
        istream >> n;
        if (!istream.fail()) 
        {
            numbers.push_back(n);
        }
        
    }
}

int main()
{
    string text = "Hello World\n";
    cout << text;

    //cin >> text;
    getline(cin, text);
    //cout << text << endl;

    Write(text, cout);

    //output to file
    ofstream output("data.txt"); //create and open a file to stream data to
    //output << text;
    int i = 4;
    output << i << endl;
    //Write(text, output);
    output.close(); // make sure to close the file after using 

    text = "";

    //input from file
    ifstream input("data.txt");
    getline(input, text);
    //Read(text, input);
    input >> i;
    //input >> text;
    input.close();

    cout << "Reading from file" << endl;
    cout << text << endl;
    cout << i << endl;

    vector<int> numbers = { 1, 2, 3, 4, 5};

    //store vector to file
    output.open("numbers.txt");
    Write(numbers, output);

    output.close();

    numbers.clear();
    //read vector from file
    input.open("numbers.txt");
    Read(numbers, input);
    input.close();

    for (int n : numbers) 
    {
        cout << n << endl;
    }







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
