// MemoryReview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Square(int& i) {
	i = i * i;
}

void Double(int* i) {
	*i = *i * 2; 
}

struct Person
{
	char name[32];
	int id;


};
int main()
{
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int var = 9;
	// declare a int reference and set it to the int variable above
	int &ref1 = var;
	// output the int variable
	cout << ref1 << endl;
	// set the int reference to some number
	ref1 = 8;
	
	// output the int variable
	cout << ref1 << endl;
	// what happened to the int variable when the reference was changed? ()
	// output the address of the int variable
	cout << &var << endl;
	// output the address of the int reference
	cout << &ref1 << endl;
	// are the addresses the same or different? (Yes they are the same)
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an intparameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	// output the int variable to the console
	int number = 5;

	Square(number); 

	cout << number << endl;


	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	int *ptr = nullptr;
	// set the int pointer to the address of the int variable created in the REFERENCE section
	ptr = &var;
	// output the value of the pointer
	cout << "Pointer output: " << ptr << endl;
	// what is this address that the pointer is pointing to? (same address as before, the address of the var variable)
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << *ptr << endl;

	Double(ptr);
	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	// output the dereference pointer
	 cout << "Dereferenced pointer after Double: " << *ptr << endl;
	// output the int variable created in the REFERENCE section
	 cout << "Updated var: " << var << endl;
	// did the int variable's value change when using the pointer?
	 //(It looks like it didnt change)
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
