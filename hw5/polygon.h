#ifndef POLYGON_H_
#define POLYGON_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"
using namespace std;
using namespace Shape_;

class Polygon : public Shape
{
public:

    //--------------------------------NESTED CLASS------------------------------------------
    class Point2D
    {
    public:
        //no parameter constructor
        Point2D();
        //constructor
        Point2D(double coorX, double coorY);

        //getters- setters
        double getCoorX()const;
        double getCoorY()const;
        void setCoorX(double x);
        void setCoorY(double y);
    
    private:
        double coorX;
        double coorY;
           
    };
    //--------------------------------------------------------------------------------------

    double area(){};          //pure virtual func. returns the area of shape
    double perimeter(){};     //pure virtual func. and returns the primeter of shape
    Shape& operator++(){};    //pure virtual func. overloads ++ to increment coordinate by one -> prefix version
    Shape& operator++(int){}; //pure virtual func. overloads ++ to increment coordinate by one -> postfix version
    Shape& operator--(){};    //pure virtual func. overload -- to increment coordinate by one -> prefix version
    Shape& operator--(int){}; //pure virtual func.overloads -- to increment coordinate by one -> postfix version
    void draw(ostream& fp){};
   
};

#endif  