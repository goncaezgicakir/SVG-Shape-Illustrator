#include "shape.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using namespace Shape_;

	//no parameter constructor
	Shape::Shape()
    {
        
    }

    //overloads == to compare shapes respect to their areas
	bool Shape::operator ==(const Shape& obj) const
    {
        return (obj.shapeArea == shapeArea);
    } 
    //overloads != to compare shapes respect to their areas
   bool Shape::operator !=(const Shape& obj) const
    {
        return (obj.shapeArea != shapeArea);
    } 
    //overloads == to compare shapes respect to their areas
    bool Shape::operator <=(const Shape& obj) const
    {
        return (obj.shapeArea <= shapeArea);
    }
    //overloads != to compare shapes respect to their areas
    bool Shape::operator >=(const Shape& obj) const
    {
        return (obj.shapeArea >= shapeArea);
    } 
    //global func to print SVG file
    ostream &operator<<(ostream &output, Shape* object)
    {   
        ofstream fp;
        //object->draw(fp);
        return output;
    }