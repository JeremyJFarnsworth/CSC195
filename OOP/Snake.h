#pragma once
#include "Animal.h"

class Snake : public Animal
{
public:
	Snake() {
		m_limbs = 0;
		has_venom = false;
		std::cout << "snake constructor\n";
	}

	~Snake() {
		std::cout << "snake destructor\n";
	}
	void Travel() override;
	void Speak() override;
protected:
	bool has_venom;

};