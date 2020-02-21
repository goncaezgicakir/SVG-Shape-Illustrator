#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace Shape_
{
	class Shape
	{
	public:	
		
		Shape();	//no parameter constructor

		virtual double area() = 0;			//pure virtual func. returns the area of shape
		virtual double perimeter() = 0;		//pure virtual func. and returns the primeter of shape

		virtual Shape& operator++() = 0; 	//pure virtual func. overloads ++ to increment coordinate by one -> prefix version
	    virtual Shape& operator++(int) = 0; //pure virtual func. overloads ++ to increment coordinate by one -> postfix version

	    virtual Shape& operator--() = 0; 	//pure virtual func. overload -- to increment coordinate by one -> prefix version
	    virtual Shape& operator--(int) = 0; //pure virtual func.overloads -- to increment coordinate by one -> postfix version

	    virtual void draw(ostream& fp) = 0;

	    virtual bool operator ==(const Shape& obj) const; //overloads == to compare shapes respect to their areas
	    virtual bool operator !=(const Shape& obj) const; //overloads != to compare shapes respect to their areas

	    virtual bool operator <=(const Shape& obj) const; //overloads == to compare shapes respect to their areas
	    virtual bool operator >=(const Shape& obj) const; //overloads != to compare shapes respect to their areas

	protected:
		double shapeArea;
		double shapePer;
	};

	//operator overload to print SVG file
	ostream &operator<<(ostream &output, Shape* object);

}//Shape_

#endif