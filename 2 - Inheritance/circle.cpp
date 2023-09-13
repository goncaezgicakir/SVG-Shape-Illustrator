#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "circle.h"


using namespace std;
//------------------------------------CIRCLE CLASS FUNCTIONS AND CONSTRUCTORS -------------------------------------

 //no parameter constructor
Circle::Circle(): radius(0.0), coorX(0.0), coorY(0.0){} //no parameter constructor

//draw function for small shape(overloaded)
void Circle::draw(ofstream &fp, char shapeCond)
{
    if(shapeCond == 'C') {
        fp << "<circle cx=\" " << coorX << "\" cy=\" " << coorY << "\" r=\" " << radius <<
           "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
    }
}

//draw function for container shape
void Circle::draw(ofstream &fp)
{
    fp << "<circle cx=\" " << coorX << "\" cy=\" " << coorY << "\" r=\" " << radius <<
       "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.3\" />" << endl;
}

//-------------------------------CIRCLE CLASS GETTERS---------------------------------------------------------------

double Circle::getRadius() const
{   return radius;
}

double Circle::getCoorX() const
{   return coorX;
}

double Circle::getCoorY() const
{   return coorY;
}

//------------------------------CIRCLE CLASS SETTERS------------------------------------------------------------------

void Circle::setRadius(double setRadius)
{   radius = setRadius;
}

void Circle::setCoorX(double setCoorX)
{   coorX = setCoorX;
}

void Circle::setCoorY(double setCoorY)
{   coorY = setCoorY;
}
