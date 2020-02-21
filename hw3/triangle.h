#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Triangle
{
public:
    Triangle(); //no parameter constructor
    Triangle(vector <double> coorValue); //constructor
    Triangle(double lengthValue); //constructor

    double getLength() const;
    vector < double > getCoordinate() const;
    void setLength(double setLength);
    void setCoordinate( vector < double > setCoordinate);
    void draw(ostream &fp) const;

    double calculatePerimeterLength(); //calculates container's perimeter length
    void calculateArea(); //calculates container's area
    double area;

    friend ostream& operator << (ostream& fp, const Triangle& object); // overloads << to draw container
    Triangle operator++(); //overload ++ to increment coordinate -> prefix version
    Triangle operator++(int); //overloads ++ to increment coordinate -> postfix version

    Triangle operator--(); //overload -- to increment coordinate -> prefix version
    Triangle operator--(int); //overloads -- to increment coordinate -> postfix version

    friend const Triangle operator +(const Triangle& object, double value); //overloads + to increment length and return a new object
    friend const Triangle operator -(const Triangle& object, double value); //overloads - to decrement length and return a new object

    friend bool operator ==(const Triangle& object1, const Triangle& object2); //overloads == to compare shapes respect to their areas
    friend bool operator !=(const Triangle& object1, const Triangle& object2); //overloads != to compare shapes respect to their areas

    static double totalAreaTri();
    static double totalPerimeterTri();


private:
    double length;      //length of triangles one side
    vector < double > coordinate;       //vector to hold coordinates of 3 nodes
    
    static int countShape;

};


#endif

