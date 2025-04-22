#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog()
	{
		m_limbs = 4;
		has_toes = false;
		std::cout << "dog constructor\n";
	}

	~Dog() {
		std::cout << "dog destructor\n";
	}
	
	void Travel()  override;
	void Speak() override;
	
protected:
	bool has_toes;
};

