#pragma once
#include <iostream>
// It's possible  class name is similar to built in classes
// use namespace wrappers to identify custom classes

namespace jjf
{
	class Point
	{
	private:
		float x, y;

	public:
		//Point() { x = 0; y = 0;} // traditional way
		Point() : x{0}, y{0} {} // Modern way
		Point(float x, float y) : x{ x }, y{ y } {}

		void Write(std::ostream& ostream);
		friend std::ostream& operator << (std::ostream& ostream, Point& p);

		void Add(Point& point);
		Point& operator + (Point& point);

		Point operator * (float s);


	};
}


