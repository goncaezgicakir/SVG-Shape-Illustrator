#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Circle
{
public:

    Circle(); //no parameter constructor
    Circle(int coorValue1, int coorValue2); //constructor
    Circle(double radiusValue); //constructor

    double getRadius() const;
    double getCoorX() const;
    double getCoorY() const;
    void setRadius(double setRadius);
    void setCoorX(double setCoorX);
    void setCoorY(double setCoorY);

    void draw(ostream &fp) const;
    double calculatePerimeterLength(); //calculates container's perimeter length

    void calculateArea(); //calculates container's area
    double area;

    friend ostream& operator <<(ostream& fp, const Circle& object); //overloads << to draw container
    Circle operator++(); //overload ++ to increment coordinate -> prefix version
    Circle operator++(int); //overloads ++ to increment coordinate -> postfix version

    Circle operator--(); //overload -- to increment coordinate -> prefix version
    Circle operator--(int); //overloads -- to increment coordinate -> postfix version

    friend const Circle operator +(const Circle& object, double value); //overloads + to increment length and return a new object
    friend const Circle operator -(const Circle& object, double value); //overloads - to decrement length and return a new object

    friend bool operator ==(const Circle& object1, const Circle& object2); //overloads == to compare shapes respect to their areas
    friend bool operator !=(const Circle& object1, const Circle& object2); //overloads != to compare shapes respect to their areas

    static double totalAreaCir(){};
    static double totalPerimeterCir(){};

private:

    double radius; //radius of circle
    double coorX;   //coorX of circle's center
    double coorY;   //coorY of circle's center

    static int countShape;
};

#endif
