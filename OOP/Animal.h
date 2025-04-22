#pragma once
#include <iostream>

class Animal
{
public:
	//Animal(){} // default constructor
	Animal() {  // constructor without parameters
		m_limbs = 0;
		m_ptr = new int(25);
		std::cout << "animal constructor\n";
	}

	Animal(int limb) { // constructor with parameters
		m_limbs = limb;
	}

	~Animal() {
		std::cout << "animal destructor\n";
		delete m_ptr;
	}

	//virtual void Travel() = 0; // pure virtual function which in turn makes the class abstract
	virtual void Travel(); 
	virtual void Speak() = 0;

	int GetLimbs() { return m_limbs; }
	void SetLimbs(int limbs) { m_limbs = limbs; }
protected:
	int m_limbs;

	int* m_ptr = nullptr;
};
