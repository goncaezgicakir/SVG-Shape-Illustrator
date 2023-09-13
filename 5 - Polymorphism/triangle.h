#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "shape.h"
using namespace std;


namespace Shape_ 
{
    class Triangle : public Shape
    {
    public:
        Triangle(); //no parameter constructor
        Triangle(vector <double> coorValue); //constructor
        Triangle(double lengthValue); //constructor

        //getters
        double getLength() const;
        vector < double > getCoordinate() const;

        //setters
        void setLength(double setLength);
        void setCoordinate( vector < double > setCoordinate);

        double area();          
        double perimeter();   

        friend ostream& operator << (ostream& fp, const Triangle& object); // overloads << to draw container
        void draw(ostream &fp);

        Shape& operator++(); //overload ++ to increment coordinate -> prefix version
        Shape& operator++(int x); //overloads ++ to increment coordinate -> postfix version
        
        Shape& operator--(); //overload -- to increment coordinate -> prefix version
        Shape& operator--(int x); //overloads -- to increment coordinate -> postfix version
        
        const Triangle operator +(double value); //overloads + to increment length and return a new object
        const Triangle operator -(double value); //overloads - to decrement length and return a new object
       
       /* bool operator ==(const Triangle& obj); //overloads == to compare shapes respect to their areas
        bool operator !=(const Triangle& obj); //overloads != to compare shapes respect to their areas*/


    private:
        double length;                  //length of triangles one side
        vector <double> coordinate;   //vector to hold coordinates of 3 nodes
       

    };

}//Shape_

#endif

