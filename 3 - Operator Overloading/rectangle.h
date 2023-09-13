#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Rectangle
{

public:
    Rectangle(); //no parameter constructor
    Rectangle(int coorValue1, int coorValue2); //constructor
    Rectangle(double heightValue, double widthValue); //constructor

    //getters
    double getHeight() const;
    double getWidth() const;
    double getCoorX() const;
    double getCoorY() const;

    //setters
    void setHeight(double setHeight);
    void setWidth(double setWidth);
    void setCoorX(double setCoorX);
    void setCoorY(double setCoorY);

    void draw(ostream &fp) const;
    double calculatePerimeterLength(); //calculates containers perimeter length
    void  calculateArea(); // calculates containers area
    double area;

    friend ostream& operator <<(ostream& fp, const Rectangle& object); //overloads <<  to draw container rectangle

    Rectangle operator++(); //overload ++ to increment coordinate -> prefix version
    Rectangle operator++(int); //overloads ++ to increment coordinate -> postfix version

    Rectangle operator--(); //overload -- to increment coordinate -> prefix version
    Rectangle operator--(int); //overloads -- to increment coordinate -> postfix version

    friend const Rectangle operator +(const Rectangle& object, double value); //overloads + to increment length and return a new object
    friend const Rectangle operator -(const Rectangle& object, double value); //overloads - to decrement length and return a new object

    friend bool operator ==(const Rectangle& object1, const Rectangle& object2); //overloads == to compare shapes respect to their areas
    friend bool operator !=(const Rectangle& object1, const Rectangle& object2); //overloads != to compare shapes respect to their areas

    static double totalAreaRec(){};
    static double totalPerimeterRec(){}



private:
    int height; //height of rectangle
    int width;  //width of rectangle
    double coorX;   //coorX for one node of rectangle
    double coorY;   //coorY for one node of rectangle

    static int countShape;

};
#endif

