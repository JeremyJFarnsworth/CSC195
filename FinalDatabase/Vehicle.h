#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Vehicle
{
public:
	enum class Types
	{
		CAR,
		PLANE,
		BOAT
	};

	
	friend std::ostream& operator<<(std::ostream& out, Vehicle& v)
	{
		v.Write(out);
		return out;
	}

	
	friend std::istream& operator>>(std::istream& in, Vehicle& v)
	{
		v.Read(std::cout, in); 
		return in;
	}

	
	friend std::ofstream& operator<<(std::ofstream& fout, Vehicle& v)
	{
		v.Write(fout);
		return fout;
	}

	
	friend std::ifstream& operator>>(std::ifstream& fin, Vehicle& v)
	{
		v.Read(fin);
		return fin;
	}

	virtual ~Vehicle() = default;

	float price;

	
	virtual void Read(std::ostream& promptOut, std::istream& in) {
		promptOut << "Enter name: ";
		std::getline(in >> std::ws, name);
		promptOut << "Enter price: ";
		in >> price;
	}


	virtual void Write(std::ostream& out) {
		out << "Name: " << name << "\nPrice: " << price << std::endl;
	}

	// For file input
	virtual void Read(std::ifstream& fin) {
		std::getline(fin >> std::ws, name);
		fin >> price;
		fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	}

	// For file output
	virtual void Write(std::ofstream& fout) {
		fout << name << '\n' << price << '\n';
	}

	virtual std::string GetName() const = 0;
	virtual Types GetType() = 0;

protected:
	std::string name;
};
