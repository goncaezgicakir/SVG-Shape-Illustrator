#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include <fstream>
using namespace std;
#include "shape.h"

namespace Shape_
{
    class Rectangle : public Shape
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
        
        
        double area();          
        double perimeter();   

        void draw(ostream &fp);
        friend ostream& operator <<(ostream& fp, const Rectangle& object); //overloads <<  to draw container rectangle

        Shape& operator++();     //overload ++ to increment coordinate -> prefix version
        Shape& operator++(int x);  //overloads ++ to increment coordinate -> postfix version
        Shape& operator--();      //overload -- to increment coordinate -> prefix version
        Shape& operator--(int x);       //overloads -- to increment coordinate -> postfix version
        
        const Rectangle operator +(double value);      //overloads + to increment length and return a new object
        const Rectangle operator -(double value);      //overloads - to decrement length and return a new object
        
        /*bool operator ==(const Rectangle& obj) const;    //overloads == to compare shapes respect to their areas
        bool operator !=(const Rectangle& obj) const;   //overloads != to compare shapes respect to their areas*/


    private:
        int height; //height of rectangle
        int width;  //width of rectangle
        double coorX;   //coorX for one node of rectangle
        double coorY;   //coorY for one node of rectangle
       
       
    };


}//Shape_

#endif

