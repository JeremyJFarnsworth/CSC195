// OperatorOverload.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Point.h"
#include <ostream>

using namespace jjf;
using namespace std;

// operator overloads inside a class just requires the right hand side & the left hand side
// of the symbol as parameter
// Left hand side is the instance that we are in right now
//Point& operator + (Point& p1, Point& p2)
//{
//    Point point;
//    point.x = p1.x + p2.x;
//    point.y = p1.y + p2.x;
//    return point;
//}

//void operator << (ostream& ostream,Point& p)
//    {
//    ostream << p.x << " : " << p.y << endl;
//    }



int main()
{
    Point point1(10, 14);

    point1.Write(cout);

    Point point2(5, 8);
    //point1.Add(point2); ----- instead of a method call
    Point point3 = (point1 + point2) * 3.0f;  // suntactical suger(makes code prettier), operators user-defined meaning

    //point3.Write(cout);

    cout << point3 << point2;
    
}


