#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include <fstream>
#include "shape.h"
using namespace std;

namespace Shape_
{

    class Circle : public Shape
    {
    public:

        Circle(); //no parameter constructor
        Circle(int coorValue1, int coorValue2); //constructor
        Circle(double radiusValue); //constructor

        //getters
        double getRadius() const;
        double getCoorX() const;
        double getCoorY() const;

        //setters
        void setRadius(double setRadius);
        void setCoorX(double setCoorX);
        void setCoorY(double setCoorY);

        double area();          
        double perimeter();   

        void draw(ostream &fp);
        friend ostream& operator <<(ostream& fp, const Circle& object);         //overloads << to draw container
        
        Shape& operator++();        //overload ++ to increment coordinate -> prefix version
        Shape& operator++(int x);      //overloads ++ to increment coordinate -> postfix version

        Shape& operator--();     //overload -- to increment coordinate -> prefix version
        Shape& operator--(int x);     //overloads -- to increment coordinate -> postfix version

        const Circle operator +(double value);   //overloads + to increment length and return a new object
        const Circle operator -(double value);   //overloads - to decrement length and return a new object

        /*bool operator ==(const Circle& obj) const;   //overloads == to compare shapes respect to their areas
        bool operator !=(const Circle& obj) const;   //overloads != to compare shapes respect to their areas*/


    private:

        double radius; //radius of circle
        double coorX;   //coorX of circle's center
        double coorY;   //coorY of circle's center
       
    };

}//Shape_

#endif
