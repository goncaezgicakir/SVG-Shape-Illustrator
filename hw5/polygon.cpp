#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "polygon.h"
#include "shape.h"
using namespace std;
using namespace Shape_;



//---------------------------INNER CLASS POINT2D CONSTRUCTORS-----------------------------------------------

//no parameter constructor
Polygon::Point2D::Point2D(): coorX(0), coorY(0){}

//constructor
Polygon::Point2D::Point2D(double x, double y)
{
    coorX = x;
    coorY = y;
}



//--------------------------INNER CLASS POINT2D GETTERS AND SETTERS------------------------------------------
//getters and setters
double Polygon::Point2D::getCoorX()const
{
    return coorX;
}
double Polygon::Point2D::getCoorY()const
{
    return coorY;
}

void Polygon::Point2D::setCoorX(double x)
{
    coorX = x;
}
void Polygon::Point2D::setCoorY(double y)
{
    coorY = y;
}
